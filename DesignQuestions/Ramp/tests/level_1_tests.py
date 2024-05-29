import inspect, os, sys

current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from timeout_decorator import timeout
import unittest
from cloud_storage_impl import CloudStorageImpl


class Level1Tests(unittest.TestCase):
    """
    The test suit below includes 10 tests for Level 1.

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
    def test_level_1_case_01_add_and_get_in_root(self):
        self.assertTrue(self.storage.add_file("/file.txt", 10))
        self.assertEqual(self.storage.get_file_size("/file.txt"), 10)
        self.assertEqual(self.storage.delete_file("/file.txt"), 10)

    @timeout(0.4)
    def test_level_1_case_02_add_and_get_in_directory(self):
        self.assertTrue(self.storage.add_file("/directory/dir/file1.txt", 15))
        self.assertTrue(self.storage.add_file("/directory/file2.mp4", 79))
        self.assertEqual(self.storage.get_file_size("/directory/dir/file1.txt"), 15)
        self.assertEqual(self.storage.get_file_size("/directory/dir/file1.txt"), 15)
        self.assertEqual(self.storage.get_file_size("/directory/file2.mp4"), 79)

    @timeout(0.4)
    def test_level_1_case_03_add_multiple_times(self):
        self.assertTrue(self.storage.add_file("/dir/file1.mov", 20))
        self.assertEqual(self.storage.get_file_size("/dir/file1.mov"), 20)
        self.assertFalse(self.storage.add_file("/dir/file1.mov", 70))
        self.assertFalse(self.storage.add_file("/dir/file1.mov", 90))
        self.assertEqual(self.storage.get_file_size("/dir/file1.mov"), 20)

    @timeout(0.4)
    def test_level_1_case_04_delete_file(self):
        self.assertTrue(self.storage.add_file("/src/main.cpp", 20))
        self.assertEqual(self.storage.get_file_size("/src/main.cpp"), 20)
        self.assertEqual(self.storage.delete_file("/src/main.cpp"), 20)
        self.assertIsNone(self.storage.get_file_size("/src/main.cpp"))

    @timeout(0.4)
    def test_level_1_case_05_delete_multiple_times(self):
        self.assertTrue(self.storage.add_file("/movie.mp4", 600))
        self.assertTrue(self.storage.add_file("/lib/bin/exec.sh", 20))
        self.assertEqual(self.storage.get_file_size("/lib/bin/exec.sh"), 20)
        self.assertEqual(self.storage.delete_file("/lib/bin/exec.sh"), 20)
        self.assertIsNone(self.storage.get_file_size("/lib/bin/exec.sh"))
        self.assertIsNone(self.storage.delete_file("/lib/bin/exec.sh"))
        self.assertTrue(self.storage.add_file("/lib/bin/exec.sh", 50))
        self.assertEqual(self.storage.get_file_size("/lib/bin/exec.sh"), 50)

    @timeout(0.4)
    def test_level_1_case_06_unexisting_file(self):
        self.assertIsNone(self.storage.get_file_size("/nofile.gif"))
        self.assertIsNone(self.storage.delete_file("/nofile.gif"))
        self.assertIsNone(self.storage.get_file_size("/nofile.gif"))
        self.assertTrue(self.storage.add_file("/nofile.gif", 100000))
        self.assertEqual(self.storage.get_file_size("/nofile.gif"), 100000)

    @timeout(0.4)
    def test_level_1_case_07_similar_names(self):
        self.assertTrue(self.storage.add_file("/file/file.txt", 50))
        self.assertTrue(self.storage.add_file("/file.png", 80))
        self.assertEqual(self.storage.delete_file("/file/file.txt"), 50)
        self.assertIsNone(self.storage.delete_file("/file.p"))
        self.assertIsNone(self.storage.delete_file("/fil"))
        self.assertIsNone(self.storage.get_file_size("/file/file.txt"))
        self.assertEqual(self.storage.get_file_size("/file.png"), 80)
        self.assertTrue(self.storage.add_file("/fil", 5))
        self.assertEqual(self.storage.get_file_size("/fil"), 5)

    @timeout(0.4)
    def test_level_1_case_08_mixed_1(self):
        self.assertTrue(self.storage.add_file("/file1.txt", 6))
        self.assertFalse(self.storage.add_file("/file1.txt", 5))
        self.assertTrue(self.storage.add_file("/file2.txt", 3))
        self.assertEqual(self.storage.get_file_size("/file1.txt"), 6)
        self.assertIsNone(self.storage.get_file_size("/file3.txt"))
        self.assertEqual(self.storage.delete_file("/file1.txt"), 6)
        self.assertTrue(self.storage.add_file("/file1.txt", 2))
        self.assertEqual(self.storage.get_file_size("/file1.txt"), 2)

    @timeout(0.4)
    def test_level_1_case_09_mixed_2(self):
        self.assertTrue(self.storage.add_file("/dir1/dir2/file.txt", 10))
        self.assertFalse(self.storage.add_file("/dir1/dir2/file.txt", 5))
        self.assertEqual(self.storage.get_file_size("/dir1/dir2/file.txt"), 10)
        self.assertIsNone(self.storage.delete_file("/non-existing.file"))
        self.assertEqual(self.storage.delete_file("/dir1/dir2/file.txt"), 10)
        self.assertIsNone(self.storage.get_file_size("/not-existing.file"))

    @timeout(0.4)
    def test_level_1_case_10_dir_structure_mixed_1(self):
        self.assertTrue(self.storage.add_file("/dir2/dir1/file1.txt", 7))
        self.assertTrue(self.storage.add_file("/intro/slides.pptx", 106))
        self.assertTrue(self.storage.add_file("/dir1/dir/file2.mp4", 105))
        self.assertTrue(self.storage.add_file("/intro.p", 20))
        self.assertTrue(self.storage.add_file("/dir1/dir2/file1.txt", 27))
        self.assertTrue(self.storage.add_file("/intro.pdf", 33))
        self.assertTrue(self.storage.add_file("/dir1/dir2/file2.log", 82))
        self.assertTrue(self.storage.add_file("/dir1/dir1/dirt.py3", 122))
        self.assertTrue(self.storage.add_file("/dir1/dir3/file2.mp4", 149))
        self.assertEqual(self.storage.delete_file("/dir1/dir1/dirt.py3"), 122)
        self.assertEqual(self.storage.delete_file("/dir1/dir2/file2.log"), 82)
        self.assertEqual(self.storage.delete_file("/intro/slides.pptx"), 106)
        self.assertEqual(self.storage.get_file_size("/dir1/dir3/file2.mp4"), 149)
        self.assertEqual(self.storage.get_file_size("/dir2/dir1/file1.txt"), 7)
        self.assertIsNone(self.storage.get_file_size("/intro/slides.pptx"))
        self.assertEqual(self.storage.get_file_size("/dir1/dir2/file1.txt"), 27)
        self.assertEqual(self.storage.get_file_size("/dir1/dir/file2.mp4"), 105)
        self.assertIsNone(self.storage.get_file_size("/dir1/dir2/file2.log"))
        self.assertIsNone(self.storage.get_file_size("/dir1/dir1/dirt.py3"))
        self.assertEqual(self.storage.get_file_size("/intro.pdf"), 33)
        self.assertEqual(self.storage.get_file_size("/intro.p"), 20)
