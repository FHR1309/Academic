

#include <bits/stdc++.h>
using namespace std;

int main(){

    int R,P;
    cout<<"Enter the resource and process number : ";
    cin>>R>>P;

    //int rex[R],rav[R];

    //int cam[P][R], rm[P][R];
    ///*
    int rav[] = {2,1,0,0};
    int cam[P][R] = { {0,0,1,0},
                    {2,0,0,1},
                    {0,1,2,0}};


    int rm[P][R] = { {2,0,0,1},
                   {1,0,1,0},
                   {2,1,0,0}};
//*/

                   /*

   /*cout<<"\nEnter the existing resource number : \n";

    for(int i=0; i<R; i++){
        cin>>rex[i];
    }*/
/*
    cout<<"\nEnter the available resource number : \n";

    for(int i=0; i<R; i++){
        cin>>rav[i];
    }

    cout<<"\nEnter the current allocation matrix : \n";

    for(int i=0; i<P; i++){
        for(int j=0; j<R; j++){
            cin>>cam[i][j];
        }
    }


    cout<<"\nEnter the requested resource matrix : \n";

    for(int i=0; i<P; i++){
        for(int j=0; j<R; j++){
            cin>>rm[i][j];
        }
    }
 */

    bool procdone[P] = {false};
    bool flag = false;


    for(int k = 0; k<P; k++)
    {
        flag = false;

        for(int i=0; i<P; i++){

            //cout<<endl;
            for(int j=0; j<R; j++){

               // cout<<rm[i][j]<<" ";
                if(rm[i][j]>rav[j]){
                    break;
                }

                if(j == R-1 && !procdone[i] ){
                    procdone[i] = true;
                    //flag = true;
                    //cout<<endl<<"found match  ";
                    for(int l=0; l<R; l++){
                        rav[l] += cam[i][l];
                        rm[i][l] = 0;
                        cam[i][l] = 0;
                        //cout<<rav[l]<<" ";
                    }
                }
            }
        }
        //cout<<endl<<endl;

        /*if(!flag) {
            cout<<"\n\tDead lock happened\n";
            return 0;
        }*/


    }

    for(int i = 0; i<P; i++){
        if(!procdone[i]){
          cout<<"\n\tDead lock happened\n";
            return 0;
        }
    }

    cout<<"\n\tDead lock not  happened\n";




}
