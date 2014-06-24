#include <cstdlib>
#include <iostream>

using namespace std;

// print app title page
void printTitle();
// get product entry count
int getProdCntNum();
// product info getter
float getVal();
// print user input results
void printResults(float prodDataArr[][5], int prodNum);
// print profits
void printProfits(float prodDataArr[][5], int prodNum);

int main(int argc, char *argv[])
{
    int i, j, prodNum;
    
    // print app title
    printTitle();
    
    // gather product entry count
    cout << "Number of Product:";
    prodNum = getProdCntNum();
    
    // configure product data array
    float prodDataArr[prodNum][5];
    
    // product values entry
    for(i = 0; i < prodNum; ++i){
    	
    	// product value fields entry
    	for(j = 0; j < 5; ++j){
    		
    		// gather user data
    		switch(j){
    			case 0:
    				// get product id
                    cout << endl <<  "Product ID: ";
    			break;
    			case 1:
    				// get num product items
                    cout << endl << "# of items: ";
    			break;
    			case 2:
    				// get unit price
                    cout << endl << "Unit Price($): ";
    			break;
    			case 3:
    				// get sale price
                    cout << endl << "Sale Price($): ";
    			break;
    			case 4:
    				// get num of sold items
                    cout << endl << "# of items sold: ";
    			break;
    		}
    		
    		// capture values
    		prodDataArr[i][j] = getVal();
    		
    	}
    }
    
    // clear line
    cout << endl;
    
    // print results
    printResults(prodDataArr, prodNum);
    
    // print results
    printProfits(prodDataArr, prodNum);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

// print app title page
void printTitle(){
     
     cout << "**********************************" << endl;
     cout << "Profit Calculator" << endl;
     cout << endl;
     cout << "V.1.0" << endl;
     cout << endl;
     cout << "Developed by Robert S. McDowell" << endl;
     cout << "**********************************" << endl;
     cout << endl;
     
}

// get product entry
int getProdCntNum(){
    int prodNum;
    
    cin >> prodNum;
    if(cin.fail()){
        cout << endl << "Please enter a valid integer value:";
        cin.clear();
        cin.ignore();
        getProdCntNum();
    }
    
    return prodNum;
}

// product info getter
float getVal(){
      float prodVal;
    
    cin >> prodVal;
    if(cin.fail()){
        cout << endl << "Please enter a valid value:";
        cin.clear();
        cin.ignore();
        getVal();
    }
    
    return prodVal;
}

// print user input results
void printResults(float prodDataArr[][5], int prodNum){
     int i, j;
     
     cout << "Product ID\t# of items\tUnit Price($)\tSale Price($)\t# of items sold" << endl << endl;
     
     for(i = 0; i < prodNum; ++i){
           for(j = 0; j < 5; ++j){
                 cout << prodDataArr[i][j] << "\t\t";
           }
           cout << endl;
     }
}

// print profits
void printProfits(prodDataArr[][5],prodNum){
     int i;
     float profit;
     
     for(i = 0; i < prodNum; ++i){
	      profit = (prodDataArr[i][3] * prodDataArr[i][4]) – (prodDataArr[i][1] * prodDataArr[i][2]);
          cout << "Current Profit of item number " << prodDataArr[i][0] << "$" << profit << endl;
     }	
}
