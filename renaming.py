import glob
import re
import os

STANDARD_PATTERN = r"LeetCode\-[0-9]+(\-[A-Za-z\-])+"
NON_STANDARD_PATTERN1 = r"[0-9]+\.(\ [A-Za-z])+"

def make_name_standard1(path: str) -> str:
	number = path.split(' ')[0][:-1]
	words = path.split(' ')[1:]
	return "-".join(["LeetCode"] + [number] + words)

NON_STANDARD_PATTERNS = {
	NON_STANDARD_PATTERN1: make_name_standard1
}

if __name__ == '__main__':
	folder_list = glob.glob("*")
	unstandard_folders = [f for f in folder_list if not re.match(STANDARD_PATTERN, f)]

	for f in unstandard_folders:
		for p, func in NON_STANDARD_PATTERNS.items():
			if re.match(p, f):
				new_path = func(f)
				print("rename old: {old} to new: {new}".format(old=f, new=new_path))
				os.rename(f, new_path)

