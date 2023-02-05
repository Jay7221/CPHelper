import sys
import os
import shutil
import subprocess
import json

STANDARD_CONTEST_FOLDER = "/home/oneautumleaf/Desktop/Contest_Template"
STANDARD_PROBLEM_FOLDER = "/home/oneautumleaf/Desktop/Contest_Template/Problem"


class Contest:
    def __init__(self, folder):
        self.folder = folder
        self.path = self.folder.path
        self.name = self.folder.name
        self.settings = self.folder.settings
    def __str__(self):
        return self.name
    def loadProblems(self):
        self.problems = []
        for file in os.listdir(os.path.join(self.path)):
            folder = Folder(file)
            if folder.isProblem():
                self.problems.append(Problem(folder))


def runCpp(fileName, argv = []):
    subprocess.run(['g++', '-o', 'main', fileName])
    runList = [fileName]
    runList.extend(argv)
    subprocess.run(runList)

class Problem:
    def __init__(self, folder):
        self.path = self.folder.path
        self.name = self.folder.name
        self.settings = self.folder.settings
        self.generator = os.path.join(self.path, 'generator.cpp')
        self.solution = os.path.join(self.path, 'solution.cpp')
        self.checker = os.path.join(self.path, 'checker.cpp')
        self.test = os.path.join(self.path, 'test.cpp')

    def __init__(self, path):
        self.path = path
        self.name = os.path.basename(path)
        


    def __str__(self):
        return self.name
    def getTestcases(self):
        return self.settings['testcases']
    def getSolutions(self):
        return self.settings['solutions']

    def generateTestcase(self, path):
        subprocess.run(['g++', '-o', 'main', self.generator])
    def generateTestcases(self):
        for file in os.listdir(os.path.join(self.path, 'testcases')):
            self.generateTestcase(os.path.join(self.path, file))


class Folder:
    def __init__(self, path):
        self.path = path
        self.name = os.path.basename(self.path)
        with open(os.path.join(self.path, 'settings.json')) as fp:
            self.settings = json.load(fp)
    def isContest(self):
        return self.settings['isContest']
    def isProblem(self):
        return self.settings['isProblem']


class Manager:
    def __init__(self):
        self.path = os.getcwd()
        self.folder = Folder(self.path)
        if self.folder.isContest():
            self.contest = Contest(self.folder)
        elif self.folder.isProblem():
            self.problem = Contest(self.problem)





def startContest(contestName):
    shutil.copytree(STANDARD_CONTEST_FOLDER, contestName)

def createNewProblem(problemName):
    shutil.copytree(STANDARD_PROBLEM_FOLDER, problemName)


def runFile(fileName):
    subprocess.run(["g++", "-std=c++17", "-o", "main", fileName, "&&", "./main"])


if len(sys.argv) > 1:
    if sys.argv[1] == "start":
        startContest(sys.argv[2])
    if sys.argv[1] == "run":
        runFile(sys.argv[2])
    if sys.argv[1] == "new":
        createNewProblem(sys.argv[2])