// Random Events
#include <iostream>
#include <vector>
using namespace std;

struct test
{
    int index;
    double perc;
};

double obtainPercentage(vector<int> permu, vector<test> testVec)
{
    int permuSize = permu.size();
    int testVecSize = testVec.size();

    int unorgPos = -1; 
    double res = 1;

    for(int i = 1; i <= permuSize; i++ )
    {
        
        if(i != permu[i-1]) 
        {
            //cout << "unpos: "<<unorgPos<< endl;
            unorgPos = i;
        }
    }

    if(unorgPos == -1){
        res = 0;
    }
    else
    {
        for(int i = 0; i < testVecSize; i++)
        {
            //cout << "ind" << testVec[i].index << endl;
            if(testVec[i].index >= unorgPos)
            {
                //cout << "res " <<res << endl;
                res *= (1-testVec[i].perc);
            }
        }
    }
    

    return 1-res;

    
}

int main()
{
    int testTotal, permuLength, expTotal, ind;
        

    vector<test> testVec;
    test t;

    vector<int> permu;
    
    int temp;
    double res =1, perc;
    

    cin >> testTotal;

    for(int i = 0; i < testTotal; i++)
    {
        res = 1;
        cin >> permuLength >> expTotal;

        for(int j = 0; j < permuLength; j++)
        {
            cin >> temp;
            
            permu.push_back(temp);
        }

        for(int k = 0; k < expTotal; k++)
        {
            cin >> t.index >> t.perc;
            //cout << "first" << t.index <<  "perc " << t.perc << endl;
            testVec.push_back(t);    
        }
        cout << obtainPercentage(permu, testVec) << endl;
        testVec.clear();
        permu.clear();

    }
    return 0;
}