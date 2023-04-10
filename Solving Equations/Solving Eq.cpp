#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long double matrix(long double arr[],int size);
int main(){
	int select=0;
	while(select==0){
	int numofequ,count=0;
	cout<<"Number of equations can be solved is 9"<<endl;
	cout<<"Enter number of equations: ";
	a:
	cin>>numofequ;
	if(numofequ<2 || numofequ>9){
		cout<<"Enter number from 2 : 9: ";
		goto a;
	}
	long double*unknown=new long double[numofequ];//المجاهيل
	long double*element=new long double[int(pow(numofequ,2.0))];//المعاملات
	long double*absolute=new long double[numofequ];//الحدود المطلقة
	long double*delta=new long double[numofequ+1];
	long double*deltamat=new long double[int(pow(numofequ,2.0))];
	for(int i=0;i<numofequ;i++){
		cout<<"Enter the elements of equation no. "<<i+1<<endl;
		for(int j=0;j<=numofequ;j++){
			if(j==numofequ){cin>>absolute[i];}
			else{
				cin>>element[count];
				count++;
			}
		}
	}

	cout<<"Your equations:"<<endl;
	count=0;
	for(int i=1;i<=numofequ;i++){
		for(int j=0;j<=numofequ;j++){
			if(j==numofequ){
				cout<<" = "<<absolute[i-1]<<endl;
				continue;
			}
				cout<<element[count]<<" X"<<j+1;
			if(j<numofequ-1){cout<<" + ";}
			count++;
		}
	}
	cout<<"____________________________________________________________"<<endl;
	cout<<"Your unknowns:"<<endl;
	count=0;
	delta[0]=matrix(element,numofequ);
	if(delta[0]==0){cout<<"Equations can't be solved together"<<endl;}
	else{
		for(int i=1;i<=numofequ;i++){
		int check=i-1;
		for(int j=0;j<pow(numofequ,2.0);j++){
			if(j-check==numofequ || j-check==0){
				deltamat[j]=absolute[count];
				check=j;
				count++;
			}
			else{
				deltamat[j]=element[j];
			}
		}
		cout<<"X"<<i<<" = "<<matrix(deltamat,numofequ)<<" / "<<delta[0]<<" = "<<matrix(deltamat,numofequ)/delta[0]<<endl;
		count=0;
	}
	}
	cout<<"____________________________________________________________"<<endl;
	}
}
long double matrix(long double arr[],int numofequ){
	int subsize=pow(numofequ-1,2.0);
	long double value = 0;
	if (numofequ == 2){
		return (arr[0]*arr[3] - arr[1]*arr[2]);
	}
	else{
		for(int i = 0;i < numofequ;i++){
			long double*arr1=new long double[subsize];
			int check=i,count=0;
			for(int j = numofequ;j < pow(numofequ,2.0);j++){
					if(j-check!=numofequ){
						arr1[count]=arr[j];
						count++;
					}
					else
						check=j;
			}
			value+=pow(-1.0,i)*arr[i]*matrix(arr1,numofequ-1);
		}
		return value;
	}
}