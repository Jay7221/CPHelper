import os
import subprocess
import json
import shutil

'''
    The settings.json file contains : 
    1. name - The name of Problem or Contest.
    2. path - The path or location of the Problem or Contest
    3. problems(for Contest) - A list of names of all the Problems in the Contest 
    4. testcases(for Problem) - A list of names of all the testcases in the Problem
    5. expected-outputs(for Problem) - A dictionary containing a expected output name for each testcase
    6. test-outputs(for Problem) - A dictionary containing a test output name for each testcase
    7. generator - The name of generator code file
    8. solution - The name of the solution code file
    9. checker - The name of the checker code file
    10. test - The name of the test code file
'''

CONTEST_TEMPLATE = '/home/oneautumleaf/Desktop/Project_Manager/ContestTemplate'


def run_cpp(file, argv):
    '''Runs a .cpp file with the given command line arguments'''
    runList = ['g++', '-o', 'main', file]
    subprocess.run(runList)
    runList = ['./main']
    runList.extend(argv)
    subprocess.run(runList)

# def trim(filepath):
#     for elem in os.walk(filepath):
#         if os.path.isfile(elem):
#             print(f"Deleting {elem}")


def run(file, argv=[]):
    run_cpp(file, argv)


def execute(file, argv=[]):
    '''Executes the given file on the basis of it's extension and pass argv as it's command line arguments'''
    pass


class Contest:
    def __init__(self, path):
        pass

    def generateTestcases(self):
        '''Runs generateTestcases method for each Problem and Contest in the Contest'''
        pass

    def generateExpectedSolutions(self):
        '''Runs generateExpectedSolutions method for each Problem and Contest in the Contest'''
        pass

    def generateTestSolutions(self):
        '''Runs generateTestSolutions method for each Problem and Contest in the Contest'''
        pass

    def checkSolutions(self):
        '''Runs checkSolutions method for each Problem and Contest in the Contest'''
        pass

    def newProblem(self, name):
        '''Runs newProblem method for each Problem and Contest in the Contest'''
        pass


class Problem:
    def __init__(self, name, path):
        '''If Problems already exits opens it or else creates a new problem at location {path} with name {name}'''
        self.name = name
        self.path = os.path.join(path, name)
        self.settingsPath = os.path.join(self.path, 'settings.json')

        if not os.path.isdir(self.path):
            shutil.copytree(CONTEST_TEMPLATE, self.path)
        with open(self.settingsPath) as fp:
            self.settings = json.load(fp)

        self.settings['name'] = self.name
        self.settings['path'] = self.path

    def __del__(self):
        outfile = open(self.settingsPath, "w")
        json.dump(self.settings, outfile)
        outfile.close()

    def generateTestcases(self):
        '''Genrates test cases for the Problem. The testcase paths are taken from the settings.json file'''
        for testcaseFile in self.settings['testcases']:
            generator = self.settings['generator']
            run(generator, [testcaseFile])
        pass

    def generateExpectedSolutions(self):
        '''Generates expected solutions for the Problem. The expected solution files and testcases files are taken from settings.json file'''
        for testcaseFile in self.settings['testcases']:
            expectedSolutionFile = self.settings['expected-solutions'][testcaseFile]
            run(self.settings['solution'], [
                testcaseFile, expectedSolutionFile])

    def generateTestSolutions(self):
        '''Generates solutions using the code in test.cpp file'''
        for testcaseFile in self.settings['testcases']:
            testSolutionFile = self.settings['test-solutions'][testcaseFile]
            run(self.settings['test'], [testcaseFile, testSolutionFile])

    def checkSolutions(self):
        '''Runs the checker.cpp file and passes it three arguments, testcase, expected_solution and test_solution'''

        for testcaseFile in self.settings['testcases']:
            testSolutionFile = self.settings['test-solutions'][testcaseFile]
            expectedSolutionFile = self.settings['expected-solutions'][testcaseFile]
            run(self.settings['test'], [testcaseFile,
                expectedSolutionFile, testSolutionFile])

    def addTestCase(self, testcaseNum):
        '''Adds a testcase with testcaseNum'''

        pass

    def setNoTestcases(self, numTestcases):
        '''Clear the testcases and sets the number of testcases to {numTestcases}'''
        pass


class Manager:
    def __init__(self):
        '''Initializes the manager'''
        pass

    def isValidSportsDir(self):
        '''Returns True is there is a settings.json file meaning this is a valid sports programming directory'''
        return os.path.isfile('settings.json')

    def cmdHelper(self, argv):
        '''Deals with all the command line argurments passed to the program'''
        pass
