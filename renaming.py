import glob
import re
import os

OLD_PATTERN = "LeetCode-[0-9]+-.+"


# Reformat pattern `LeetCode-<num>-Problem-Name` to `<num>. Problem Name`
def reformat_dir_pattern(orgin: str) -> str:
    number = re.search(r"[0-9]+", orgin)
    names = re.findall(r"[A-Za-z]+", orgin)[1:]
    return " ".join([number.group() + "."] + names)


if __name__ == "__main__":
    folder_list = glob.glob("*")
    target_folders = [f for f in folder_list if re.match(OLD_PATTERN, f)]

    # Rename the old name to new names. If a new name already exists, then force deleting the old directory.
    for f in target_folders:
        new_name = reformat_dir_pattern(f)
        if os.path.exists(new_name):
            os.system("rm -rf " + f)
        else:
            os.rename(f, new_name)
