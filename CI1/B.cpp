// Got Any Grapes?
// Autor: Joel Ramos - A01245083
// Date: 26/Oct/2021
// Constaints:
// Andrew wants Green Grapes only, Dimitry despise Black Grapes and Michael is pleased with any Grapes. 
#include <iostream>
using namespace std;

// Function that returns if there are grapes for everybody
// Complexity: O(1)
bool solveGrapes(int iGG, int iPG, int iBG, int iA,int iD, int iM) {
    // If there are not enough Green Grapes for Andrew, then there are not enough grapes for everybody
    if (iA <= iGG) {
        // Acumulate the Grapes that aren't Black
        int iNotBlack = (iGG-iA) + iPG;
        // If there are not enough Grapes for Dimitry, then there are not enough grapes for everybody
        if (iD <= iNotBlack) {
            // Acumulate the rest of the Grapes
            int iRest = (iNotBlack-iD) + iBG;
            // If there are not enough Grapes for Michael, then there are not enough grapes for everybody
            if (iM <= iRest) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    // Green, Purple ande Black Grapes
    int iGreenGrapes, iPurpleGrapes, iBlackGrapes;
    // Andrew's Grapes, Dmitry's Grapes and Michal's Grapes
    int iAndrewGrapes, iDmitryGrapes, iMichalGrapes;

    // Read the number of grapes for each person
    cin >> iAndrewGrapes >> iDmitryGrapes >> iMichalGrapes;

    // Read the number of grapes
    cin >> iGreenGrapes >> iPurpleGrapes >> iBlackGrapes;

    // Calculate the number of grapes for each person
    cout << (solveGrapes(iGreenGrapes, iPurpleGrapes, iBlackGrapes, iAndrewGrapes, iDmitryGrapes, iMichalGrapes) ? "YES" : "NO" )<< endl;
    
    return 0;
}
