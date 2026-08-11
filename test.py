import os
import subprocess

# =========================
# 設定
# =========================

ROOT = "."
DOT_FILE = "test.dot"
OUTPUT_FILE = "output.png"

# 不想顯示的資料夾
IGNORE_DIRS = {
    ".git",
    "__pycache__",
    ".dSYM",
}

# 不想顯示的檔案
IGNORE_FILES = {
    ".DS_Store",
}

# =========================
# DOT Escape
# =========================

def escape(text):
    return text.replace("\\", "\\\\").replace('"', '\\"')


# =========================
# 產生 Node
# =========================

def write_node(f, path, is_dir):
    name = escape(path)

    if is_dir:
        f.write(
            f'    "{name}" '
            '[shape=folder, style="filled", fillcolor="lightgreen"];\n'
        )
    else:
        f.write(
            f'    "{name}" '
            '[shape=box, style="filled", fillcolor="lightblue"];\n'
        )


# =========================
# 掃描資料夾
# =========================

def generate_dot(root):
    with open(DOT_FILE, "w", encoding="utf-8") as f:

        f.write("digraph G {\n")

        f.write('    graph [bgcolor="white"];\n')
        f.write('    graph [rankdir=TB];\n')

        # Root
        write_node(f, root, True)

        for current, dirs, files in os.walk(root):

            # 過濾資料夾
            dirs[:] = [
                d for d in dirs
                if d not in IGNORE_DIRS
            ]

            # 排序
            dirs.sort()
            files.sort()

            # 資料夾
            for directory in dirs:

                child = os.path.join(current, directory)

                write_node(f, child, True)

                f.write(
                    f'    "{escape(current)}" '
                    f'-> "{escape(child)}";\n'
                )

            # 檔案
            for filename in files:

                if filename in IGNORE_FILES:
                    continue

                child = os.path.join(current, filename)

                write_node(f, child, False)

                f.write(
                    f'    "{escape(current)}" '
                    f'-> "{escape(child)}";\n'
                )

        f.write("}\n")


# =========================
# 呼叫 Graphviz
# =========================

def generate_png():

    try:

        subprocess.run(
            [
                "dot",
                "-Tpng",
                DOT_FILE,
                "-o",
                OUTPUT_FILE
            ],
            check=True
        )

        print(f"完成：{OUTPUT_FILE}")

    except FileNotFoundError:

        print("找不到 Graphviz。")
        print("請先執行：brew install graphviz")


# =========================
# Main
# =========================

if __name__ == "__main__":

    generate_dot(ROOT)

    print(f"完成：{DOT_FILE}")

    generate_png()