import os
import re
import shutil
import urllib.request

ROOT = os.getcwd()
BOJ_ROOT = os.path.join(ROOT, "백준")  # BaekjoonHub 폴더 이름

MAX_CLASS = 6

# Class 폴더 준비
CLASS_DIRS = {i: os.path.join(ROOT, f"Class{i}") for i in range(1, MAX_CLASS + 1)}
UNSORTED_DIR = os.path.join(ROOT, "Unsorted")

for d in CLASS_DIRS.values():
    os.makedirs(d, exist_ok=True)
os.makedirs(UNSORTED_DIR, exist_ok=True)


# ---------- solved.ac에서 class 문제 목록 가져오기 ----------
def fetch_class_problem_ids(class_no):
    def get(url):
        req = urllib.request.Request(
            url,
            headers={"User-Agent": "Mozilla/5.0"}
        )
        return urllib.request.urlopen(req).read().decode("utf-8", errors="ignore")

    ids = set()

    for page in range(1, 30):
        url = f"https://solved.ac/class/{class_no}?page={page}"
        html = get(url)

        found = set(map(int, re.findall(r"acmicpc\.net/problem/(\d+)", html)))
        if not found:
            break

        ids |= found

    return ids


# ---------- 문제 번호 추출 ----------
def extract_problem_id(path):
    m = re.search(r"(\d{3,6})", path)
    return int(m.group(1)) if m else None


# ---------- .c 파일인지 확인 ----------
def is_c_solution(filename):
    return filename.lower().endswith(".c")


# ---------- 파일이 있으면 삭제 ----------
def remove_if_exists(p):
    if os.path.isfile(p):
        os.remove(p)


# ---------- 빈 폴더 삭제 ----------
def delete_empty_dirs(start_dir):
    for root, dirs, files in os.walk(start_dir, topdown=False):
        if not dirs and not files:
            try:
                os.rmdir(root)
            except OSError:
                pass


# ---------- 메인 ----------
def main():
    if not os.path.isdir(BOJ_ROOT):
        print(f"[skip] '{BOJ_ROOT}' 폴더 없음")
        return

    print("[1/3] Fetch class lists...")

    class_map = {}
    for c in range(1, MAX_CLASS + 1):
        class_map[c] = fetch_class_problem_ids(c)
        print(f"Class{c}: {len(class_map[c])} problems")

    print("[2/3] Move solutions...")

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
                target_dir = UNSORTED_DIR

            # 원래 파일 이름에서 제목 추출 (확장자 제거)
            safe_name = os.path.splitext(f)[0]

            # 최종 이름: 번호_문제이름.c
            target_path = os.path.join(target_dir, f"{pid}_{safe_name}.c")

            # 이미 있으면 덮어쓰기
            if os.path.exists(target_path):
                os.remove(target_path)


            os.makedirs(target_dir, exist_ok=True)
            shutil.move(full, target_path)
            moved += 1

            remove_if_exists(os.path.join(root, "README.md"))

    print(f"[3/3] moved: {moved}")
    delete_empty_dirs(BOJ_ROOT)
    print("Done.")


if __name__ == "__main__":
    main()
