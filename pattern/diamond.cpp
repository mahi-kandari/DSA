/*

    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *

*/

void pattern(int n){
    for(int i=0; i<n/2;i++){
	    for (int j=0 ; j< (n/2)-1-i; j++){
	        cout<<" ";
	    }
	    for (int k=0; k< (2*i)+1 ;k++){
	        cout<<"*";
	    }
	    cout<<endl;
	}
	for (int i=0; i<n/2;i++){
	    for (int j=0; j<i;j++){
	        cout<<" ";
	    }
	    for (int k=0 ; k< (2*((n/2)-i))-1; k++){
	        cout<<"*";
	    }
	    cout<<endl;
	}
}