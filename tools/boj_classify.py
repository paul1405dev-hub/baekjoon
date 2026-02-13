import os
import re
import shutil
import urllib.request

ROOT = os.getcwd()
BOJ_ROOT = os.path.join(ROOT, "백준")  # BaekjoonHub 루트 폴더명

MAX_CLASS = 6
CLASS_DIRS = {i: os.path.join(ROOT, f"Class{i}") for i in range(1, MAX_CLASS + 1)}
UNSORTED_DIR = os.path.join(ROOT, "Unsorted")

for d in CLASS_DIRS.values():
    os.makedirs(d, exist_ok=True)
os.makedirs(UNSORTED_DIR, exist_ok=True)

def fetch_class_problem_ids(class_no: int) -> set[int]:
    """
    solved.ac/class/{n} 페이지에서 BOJ 문제 ID를 긁어오기.
    GitHub Actions에서 403을 피하기 위해 User-Agent를 넣는다.
    """
    def get(url: str) -> str:
        req = urllib.request.Request(url, headers={"User-Agent": "Mozilla/5.0"})
        return urllib.request.urlopen(req).read().decode("utf-8", errors="ignore")

    ids: set[int] = set()

    # 1페이지부터 여러 페이지를 시도 (빈 페이지면 중단)
    for page in range(1, 30):
        url = f"https://solved.ac/class/{class_no}?page={page}"
        html = get(url)

        found = set(map(int, re.findall(r"acmicpc\.net/problem/(\d+)", html)))
        if not found:
            break
        ids |= found

    return ids

html = urllib.request.urlopen(req).read().decode("utf-8", errors="ignore")


    ids = set(map(int, re.findall(r"acmicpc\.net/problem/(\d+)", html)))

    for page in range(2, 20):  # 넉넉하게
        url_p = f"https://solved.ac/class/{class_no}?page={page}"
        req_p = urllib.request.Request(
    url_p,
    headers={"User-Agent": "Mozilla/5.0"}
)
html_p = urllib.request.urlopen(req_p).read().decode("utf-8", errors="ignore")

        found = set(map(int, re.findall(r"acmicpc\.net/problem/(\d+)", html_p)))
        if not found:
            break
        ids |= found

    return ids

def extract_problem_id(path: str) -> int | None:
    m = re.search(r"(\d{3,6})", path)
    return int(m.group(1)) if m else None

def is_c_solution(filename: str) -> bool:
    return filename.lower().endswith(".c")

def remove_if_exists(p: str):
    if os.path.isfile(p):
        os.remove(p)

def delete_empty_dirs(start_dir: str):
    for root, dirs, files in os.walk(start_dir, topdown=False):
        if not dirs and not files:
            try:
                os.rmdir(root)
            except OSError:
                pass

def main():
    if not os.path.isdir(BOJ_ROOT):
        print(f"[skip] '{BOJ_ROOT}' 폴더가 없음. BOJ_ROOT를 실제 폴더명으로 수정해줘.")
        return

    print("[1/3] Fetch solved.ac class lists...")
    class_map: dict[int, set[int]] = {}
    for c in range(1, MAX_CLASS + 1):
        class_map[c] = fetch_class_problem_ids(c)
        print(f"  - Class{c}: {len(class_map[c])} problems")

    print("[2/3] Scan solutions under BOJ root...")
    moved = 0

    for root, dirs, files in os.walk(BOJ_ROOT):
        for f in files:
            if not is_c_solution(f):
                continue

            full = os.path.join(root, f)
            pid = extract_problem_id(full)
            if pid is None:
                continue

            target_dir = None
            for c in range(1, MAX_CLASS + 1):
                if pid in class_map[c]:
                    target_dir = CLASS_DIRS[c]
                    break

            if target_dir is None:
                # 클래스 목록에 없으면 Unsorted로 보냄(원하면 continue로 바꿔도 됨)
                target_dir = UNSORTED_DIR

            target_path = os.path.join(target_dir, f"{pid}.c")
            shutil.move(full, target_path)
            moved += 1

            # 문제 폴더의 README는 필요 없으면 삭제
            remove_if_exists(os.path.join(root, "README.md"))

    print(f"[3/3] Moved {moved} file(s). Cleanup empty dirs...")
    delete_empty_dirs(BOJ_ROOT)
    print("Done.")

if __name__ == "__main__":
    main()
