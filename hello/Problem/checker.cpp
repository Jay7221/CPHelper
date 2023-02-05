#include<bits/stdc++.h>
using namespace std;
void check(int testcaseNo)
{
    printf("----------------  Checking TestCase %d  ------------------------\n", testcaseNo);
    
    printf("----------------  Checking of TestCase %d Done  ----------------\n", testcaseNo);
}
bool checkAll(ifstream &testcaseIn, ifstream &outputIn, ifstream &expectedOutputIn)
{
    cout << "Checking if output and expected output is same .." << '\n';
    string output, expectedOutput;
    int cnt = 0;
    while((outputIn >> output) || (expectedOutputIn >> expectedOutput))
    {
        ++cnt;
        if(output != expectedOutput)
        {
            cout << "Output and Expected output differ at token : " << cnt << '\n';
            return false;
        }
        output = "";
        expectedOutput = "";
    }
    cout << "Done !! Output and Expected output same !!" << '\n';
    return true;
}
int main(int argc, char **argv)
{
    ifstream testcaseIn, outputIn, expOutputIn;
    testcaseIn.open(argv[1]);
    outputIn.open(argv[2]);
    expOutputIn.open(argv[3]);
    int T;
    testcaseIn >> T;
    for(int testcase = 1; testcase <= T; ++testcase)
    {
        check(testcase);
    }
    return 0;
}