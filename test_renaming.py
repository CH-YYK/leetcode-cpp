from renaming import reformat_dir_pattern


def test_reformat_pattern():
    origin = "LeetCode-321-This-Is-A-Problem"
    result = reformat_dir_pattern(origin)
    assert result == "321. This Is A Problem"


if __name__ == '__main__':
    test_reformat_pattern()
