//Question No: 02
//Main idea of the question
// A school teacher wants to give some face masks to the students in her class.
//All the students sit in a line and each of them has a score according to his or her
//performance in the class. Students can’t change their seating order. Teacher
//wants to give at least 1 face mask to each student. If two students sit next to each
//other, then the one with the higher score must get more face masks. Note that
//when two children have equal score, they are allowed to have different number
//of face masks.
//This problem is teacher wants to minimize the total number of face masks she
//must buy.
//Algorithm
//? In this algorithm it is started from index =0
//? Firstly gave 1 mask to index 0 student.
//? Check the next student score
//? This student has got score greater than index 0 student, given mask will be
//increased by one to next(index=1) student. If next(index=1) student has got
//same score he will be given one mask and If the next(index=1) student has
//got less score than index 0 student given mask will be decreased by one.
//? After the decreasing the given masks may be 0. That cannot be happened.
//Therefore in this algorithm when the new mask count becomes 0 that mask
//count will be increased by one. Then it checks the previous student score.
//Example
//Index 0 1 2 3 4 5
//score 4 6 4 5 6 2
//Want to
//masks
//1 2 1 2 3 1
//? Index 0 student give 1 mask.
//? Next student has got 6 score. Score 6>4, therefore index 1 student will be
//given 1+1=2 masks.
//? Index 2 student has got 4 score. Score 4<6, therefore index 2 student will
//be given 2-1=1 mask.
//? Index 3 student has got 5 score. Score 5>4, therefore index 3 student will
//be given 1+1=2 masks.
//? Index 4 student has got 6 score. Score 6>5, therefore index 4 student will
//be given 2+1=3 masks.
//? Index 5 student has got 2 score. Score2<6, therefore index 5 student will be
//given 2-1=1 mask.
//

#include<iostream>  
 
using namespace std;

int find_minfm(int n,int score[]){                   
	int Total_fm=0,i,fm[100000];                     // Total_fm = total face mask ,  fm[] = face_mask array
	
	for(i=0;i<n;i++){	
		fm[0]=1;                                //give one face mask to first student in a line  (i=0) 
		
		if(score[i] < score[i+1]){
			fm[i+1]=fm[i]+1;                  	
		}
		
		else if(score[i] > score[i+1]){
			fm[i+1]=fm[i]-1;
			fm[i+1]=1;
		}
		
		else if(score[i] == score[i+1]){
			fm[i+1]=fm[i]-1;
			fm[i]=1;
		}
				
		else{
			if(fm[i] == 1){
				fm[i+1]=fm[i]+1;
			}
			
			else{
				fm[i+1]=1;
			}     
		}
			
		Total_fm=Total_fm+fm[i];                        	
	}
	return Total_fm;                                      
}


int main(){
	int score[100000],n,i,Total_facemask;
	
	cout<<("Enter number of students :")<<endl;          
	cin>>n;
	
	cout<<("Enter scores of students :")<<endl;
	
	for(i=0;i<n;i++){
		cin>>score[i];
	}
	
	Total_facemask=find_minfm(n,score);
	cout<<("Minimum number of face masks = ")<<find_minfm(n,score)<<endl; 
}
