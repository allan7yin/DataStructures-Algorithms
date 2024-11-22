import inspect, os, sys

current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from timeout_decorator import timeout
import unittest
from cloud_storage_impl import CloudStorageImpl


class Level2Tests(unittest.TestCase):
    """
    The test suit below includes 10 tests for Level 2.

    All have the same score.
    You are not allowed to modify this file,
    but feel free to read the source code
    to better understand what is happening in every specific case.
    """

    failureException = Exception

    @classmethod
    def setUp(cls):
        cls.storage = CloudStorageImpl()

    @timeout(0.4)
    def test_level_2_case_01_top_everywhere(self):
        self.assertTrue(self.storage.add_file("/file1.txt", 4))
        self.assertTrue(self.storage.add_file("/file2.mp4", 38))
        self.assertTrue(self.storage.add_file("/dir1/file3", 17))
        self.assertTrue(self.storage.add_file("/dir1/file4.txt", 6))
        self.assertTrue(self.storage.add_file("/dir1/deep_dir/file5.mkv", 40))
        self.assertTrue(self.storage.add_file("/dir2/file6.mov", 15))
        expected = ["/dir1/deep_dir/file5.mkv(40)", "/file2.mp4(38)", "/dir1/file3(17)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)

    @timeout(0.4)
    def test_level_2_case_02_top_in_directory(self):
        self.assertTrue(self.storage.add_file("/file.avi", 100))
        self.assertTrue(self.storage.add_file("/dir1/file3", 10))
        self.assertTrue(self.storage.add_file("/dir1/file4.txt", 10))
        self.assertTrue(self.storage.add_file("/dir1/deep_dir/file5.mp3", 30))
        self.assertTrue(self.storage.add_file("/dir2/file6.mp4", 60))
        expected = ["/dir1/deep_dir/file5.mp3(30)", "/dir1/file3(10)"]
        self.assertEqual(self.storage.get_n_largest("/dir1", 2), expected)

    @timeout(0.4)
    def test_level_2_case_03_top_in_deep_directory(self):
        self.assertTrue(self.storage.add_file("/file5.file", 90))
        self.assertTrue(self.storage.add_file("/dir1/file4", 49))
        self.assertTrue(self.storage.add_file("/dir1/file3.txt", 6))
        self.assertTrue(self.storage.add_file("/dir1/deep_dir/file5_huge", 1000))
        self.assertTrue(self.storage.add_file("/dir2/file6.mp4", 100))
        expected = ["/dir1/deep_dir/file5_huge(1000)"]
        self.assertEqual(self.storage.get_n_largest("/dir1/deep_dir", 4), expected)

    @timeout(0.4)
    def test_level_2_case_04_top_check_sorting(self):
        self.assertTrue(self.storage.add_file("/dir/file1.csv", 5))
        self.assertTrue(self.storage.add_file("/dirfile2csv", 5))
        self.assertTrue(self.storage.add_file("/dir/file3.txt", 5))
        expected = ["/dir/file1.csv(5)", "/dir/file3.txt(5)", "/dirfile2csv(5)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 3), expected)
        self.assertTrue(self.storage.add_file("/dir/dir/dir/dirfile", 5))
        expected = ["/dir/dir/dir/dirfile(5)", "/dir/file1.csv(5)", "/dir/file3.txt(5)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)
        self.assertTrue(self.storage.add_file("/dir/dir/dirfile", 5))
        expected = ["/dir/dir/dir/dirfile(5)", "/dir/dir/dirfile(5)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 2), expected)
        self.assertEqual(self.storage.delete_file("/dir/dir/dir/dirfile"), 5)
        expected = [
            "/dir/dir/dirfile(5)",
            "/dir/file1.csv(5)",
            "/dir/file3.txt(5)",
            "/dirfile2csv(5)",
        ]
        self.assertEqual(self.storage.get_n_largest("/dir", 5), expected)

    @timeout(0.4)
    def test_level_2_case_05_top_in_empty_directory(self):
        self.assertTrue(self.storage.add_file("/file2.jpg", 6))
        self.assertTrue(self.storage.add_file("/dir1/file3", 5))
        self.assertTrue(self.storage.add_file("/dir2/file6.mp4", 50))
        self.assertEqual(self.storage.delete_file("/dir2/file6.mp4"), 50)
        self.assertFalse(self.storage.get_n_largest("/dir2", 3))
        self.assertEqual(self.storage.delete_file("/dir1/file3"), 5)
        self.assertFalse(self.storage.get_n_largest("/dir1", 1))
        expected = ["/file2.jpg(6)"]
        self.assertEqual(self.storage.get_n_largest("/", 15), expected)

    @timeout(0.4)
    def test_level_2_case_06_top_in_unexisting_direcrtory(self):
        self.assertFalse(self.storage.get_n_largest("/dir3", 2))
        self.assertFalse(self.storage.get_n_largest("/", 3))
        self.assertTrue(self.storage.add_file("/dir1/dir2/dir3/dir1/file", 100))
        self.assertEqual(self.storage.get_file_size("/dir1/dir2/dir3/dir1/file"), 100)
        expected = ["/dir1/dir2/dir3/dir1/file(100)"]
        self.assertEqual(self.storage.get_n_largest("/dir1", 3), expected)
        self.assertFalse(self.storage.get_n_largest("/dir2", 1))
        self.assertFalse(self.storage.get_n_largest("/dir3", 1))

    @timeout(0.4)
    def test_level_2_case_07_top_mixed_1(self):
        self.assertTrue(self.storage.add_file("/dir/file1", 7))
        self.assertTrue(self.storage.add_file("/dir/file2", 7))
        self.assertTrue(self.storage.add_file("/file3", 8))
        self.assertEqual(self.storage.get_file_size("/dir/file1"), 7)
        expected = ["/file3(8)", "/dir/file1(7)", "/dir/file2(7)"]
        self.assertEqual(self.storage.get_n_largest("/", 5), expected)
        expected = ["/dir/file1(7)", "/dir/file2(7)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 3), expected)
        self.assertEqual(self.storage.get_file_size("/dir/file2"), 7)
        expected = ["/dir/file1(7)", "/dir/file2(7)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 3), expected)
        self.assertEqual(self.storage.delete_file("/dir/file1"), 7)
        expected = ["/dir/file2(7)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 2), expected)
        self.assertEqual(self.storage.delete_file("/file3"), 8)
        expected = ["/dir/file2(7)"]
        self.assertEqual(self.storage.get_n_largest("/", 2), expected)
        self.assertIsNone(self.storage.delete_file("/dir/file1"))
        self.assertEqual(self.storage.delete_file("/dir/file2"), 7)
        self.assertFalse(self.storage.get_n_largest("/", 2))

    @timeout(0.4)
    def test_level_2_case_08_top_mixed_2(self):
        self.assertFalse(self.storage.get_n_largest("/", 4))
        self.assertTrue(self.storage.add_file("/dir/file.mp4", 100))
        self.assertEqual(self.storage.get_file_size("/dir/file.mp4"), 100)
        self.assertFalse(self.storage.add_file("/dir/file.mp4", 150))
        self.assertTrue(self.storage.add_file("/file.mp4", 100))
        self.assertEqual(self.storage.get_file_size("/dir/file.mp4"), 100)
        expected = ["/dir/file.mp4(100)"]
        self.assertEqual(self.storage.get_n_largest("/", 1), expected)
        expected = ["/dir/file.mp4(100)", "/file.mp4(100)"]
        self.assertEqual(self.storage.get_n_largest("/", 2), expected)
        expected = ["/dir/file.mp4(100)", "/file.mp4(100)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)
        self.assertTrue(self.storage.add_file("/dirfile.mp4", 100))
        self.assertTrue(self.storage.add_file("/dir/library/package/exec", 1))
        self.assertEqual(self.storage.delete_file("/dir/file.mp4"), 100)
        expected = ["/dirfile.mp4(100)", "/dir/library/package/exec(1)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 3), expected)
        expected = ["/dirfile.mp4(100)", "/dir/library/package/exec(1)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 2), expected)
        expected = ["/dirfile.mp4(100)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 1), expected)
        expected = [
            "/dirfile.mp4(100)",
            "/file.mp4(100)",
            "/dir/library/package/exec(1)",
        ]
        self.assertEqual(self.storage.get_n_largest("/", 10), expected)

    @timeout(0.4)
    def test_level_2_case_09_top_mixed_3(self):
        self.assertTrue(self.storage.add_file("/lib/bin/exec.sh", 34))
        self.assertTrue(self.storage.add_file("/lib/bin/py3", 78))
        self.assertTrue(self.storage.add_file("/lib/bin/py3.9", 79))
        self.assertTrue(self.storage.add_file("/lib/bin/python3", 78))
        self.assertTrue(self.storage.add_file("/lib/bin/python3.9", 79))
        self.assertTrue(self.storage.add_file("/lib/bin/python2", 50))
        self.assertEqual(self.storage.delete_file("/lib/bin/py3"), 78)
        expected = [
            "/lib/bin/py3.9(79)",
            "/lib/bin/python3.9(79)",
            "/lib/bin/python3(78)",
            "/lib/bin/python2(50)",
            "/lib/bin/exec.sh(34)",
        ]
        self.assertEqual(self.storage.get_n_largest("/", 10), expected)
        self.assertFalse(self.storage.add_file("/lib/bin/exec.sh", 60))
        self.assertFalse(self.storage.add_file("/lib/bin/exec.sh", 300))
        self.assertTrue(self.storage.add_file("/lib/exec/exec.sh", 300))
        expected = [
            "/lib/bin/py3.9(79)",
            "/lib/bin/python3.9(79)",
            "/lib/bin/python3(78)",
            "/lib/bin/python2(50)",
        ]
        self.assertEqual(self.storage.get_n_largest("/lib/bin", 4), expected)
        self.assertFalse(self.storage.get_n_largest("/lib/bingo", 9))
        expected = [
            "/lib/bin/py3.9(79)",
            "/lib/bin/python3.9(79)",
            "/lib/bin/python3(78)",
            "/lib/bin/python2(50)",
            "/lib/bin/exec.sh(34)",
        ]
        self.assertEqual(self.storage.get_n_largest("/lib/bi", 9), expected)
        expected = [
            "/lib/exec/exec.sh(300)",
            "/lib/bin/py3.9(79)",
            "/lib/bin/python3.9(79)",
            "/lib/bin/python3(78)",
        ]
        self.assertEqual(self.storage.get_n_largest("/lib", 4), expected)
        self.assertIsNone(self.storage.delete_file("/lib/bin/py3"))
        self.assertEqual(self.storage.get_file_size("/lib/bin/exec.sh"), 34)
        self.assertIsNone(self.storage.get_file_size("/exec.sh"))
        self.assertEqual(self.storage.get_file_size("/lib/exec/exec.sh"), 300)
        self.assertIsNone(self.storage.get_file_size("/library/exec/exec.sh"))
        self.assertIsNone(self.storage.delete_file("/lib/bin/py3"))
        expected = [
            "/lib/exec/exec.sh(300)",
            "/lib/bin/py3.9(79)",
            "/lib/bin/python3.9(79)",
            "/lib/bin/python3(78)",
            "/lib/bin/python2(50)",
        ]
        self.assertEqual(self.storage.get_n_largest("/", 5), expected)
        expected = [
            "/lib/exec/exec.sh(300)",
            "/lib/bin/py3.9(79)",
            "/lib/bin/python3.9(79)",
            "/lib/bin/python3(78)",
            "/lib/bin/python2(50)",
            "/lib/bin/exec.sh(34)",
        ]
        self.assertEqual(self.storage.get_n_largest("/lib", 6), expected)
        expected = ["/lib/exec/exec.sh(300)"]
        self.assertEqual(self.storage.get_n_largest("/lib/exec", 2), expected)

    @timeout(0.4)
    def test_level_2_case_10_top_mixed_4(self):
        self.assertTrue(self.storage.add_file("/index.html", 252))
        self.assertTrue(self.storage.add_file("/collection/images/filename", 106))
        self.assertTrue(self.storage.add_file("/trash/img.img", 18))
        self.assertTrue(self.storage.add_file("/library/bin/containers/filename", 43))
        self.assertTrue(
            self.storage.add_file("/library/bin/containers/video3435.mp4", 146)
        )
        self.assertTrue(self.storage.add_file("/collection/video3435.mp4", 84))
        self.assertTrue(self.storage.add_file("/trash/filename", 12))
        self.assertTrue(self.storage.add_file("/collection/img.img", 113))
        self.assertFalse(self.storage.add_file("/trash/img.img", 29))
        self.assertTrue(self.storage.add_file("/library/main.cpp", 154))
        self.assertTrue(self.storage.add_file("/collection/pic_pic.png", 172))
        self.assertTrue(self.storage.add_file("/trash/script.js", 79))
        self.assertTrue(self.storage.add_file("/video3435.mp4", 285))
        self.assertTrue(self.storage.add_file("/collection/images/pic_pic.png", 85))
        self.assertFalse(self.storage.add_file("/collection/images/filename", 65))
        self.assertTrue(self.storage.add_file("/trash/exec.exec", 177))
        self.assertFalse(self.storage.add_file("/library/bin/containers/filename", 27))
        self.assertTrue(self.storage.add_file("/collection/audio/img.img", 224))
        self.assertTrue(self.storage.add_file("/library/bin/packages/pic_pic.png", 42))
        self.assertTrue(self.storage.add_file("/library/bin/video3435.mp4", 2))
        expected = [
            "/collection/audio/img.img(224)",
            "/collection/pic_pic.png(172)",
            "/collection/img.img(113)",
            "/collection/images/filename(106)",
            "/collection/images/pic_pic.png(85)",
            "/collection/video3435.mp4(84)",
        ]
        self.assertEqual(self.storage.get_n_largest("/collection", 13), expected)
        expected = [
            "/library/main.cpp(154)",
            "/library/bin/containers/video3435.mp4(146)",
            "/library/bin/containers/filename(43)",
            "/library/bin/packages/pic_pic.png(42)",
            "/library/bin/video3435.mp4(2)",
        ]
        self.assertEqual(self.storage.get_n_largest("/library", 17), expected)
        expected = [
            "/video3435.mp4(285)",
            "/index.html(252)",
            "/collection/audio/img.img(224)",
            "/trash/exec.exec(177)",
            "/collection/pic_pic.png(172)",
            "/library/main.cpp(154)",
        ]
        self.assertEqual(self.storage.get_n_largest("/", 6), expected)
        expected = [
            "/video3435.mp4(285)",
            "/index.html(252)",
            "/collection/audio/img.img(224)",
            "/trash/exec.exec(177)",
            "/collection/pic_pic.png(172)",
            "/library/main.cpp(154)",
            "/library/bin/containers/video3435.mp4(146)",
            "/collection/img.img(113)",
            "/collection/images/filename(106)",
            "/collection/images/pic_pic.png(85)",
            "/collection/video3435.mp4(84)",
            "/trash/script.js(79)",
            "/library/bin/containers/filename(43)",
            "/library/bin/packages/pic_pic.png(42)",
            "/trash/img.img(18)",
        ]
        self.assertEqual(self.storage.get_n_largest("/", 15), expected)
        expected = ["/collection/audio/img.img(224)"]
        self.assertEqual(self.storage.get_n_largest("/collection", 1), expected)
        expected = [
            "/video3435.mp4(285)",
            "/index.html(252)",
            "/collection/audio/img.img(224)",
            "/trash/exec.exec(177)",
            "/collection/pic_pic.png(172)",
            "/library/main.cpp(154)",
            "/library/bin/containers/video3435.mp4(146)",
            "/collection/img.img(113)",
            "/collection/images/filename(106)",
            "/collection/images/pic_pic.png(85)",
            "/collection/video3435.mp4(84)",
            "/trash/script.js(79)",
            "/library/bin/containers/filename(43)",
            "/library/bin/packages/pic_pic.png(42)",
            "/trash/img.img(18)",
            "/trash/filename(12)",
            "/library/bin/video3435.mp4(2)",
        ]
        self.assertEqual(self.storage.get_n_largest("/", 19), expected)
