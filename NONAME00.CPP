//SJF.CPP


#include <iostream.h>
#include <string.h>



void main(){

  int numberOfProcesses;
  String Pstring = "P";
  cout<<"Enter the number of processes you want to create";
  cin>>numberOfProcesses;
  int * BufferTimeUser = new int [numberOfProcesses];

  for( int i = 0 ; i < numberOfProcesses; i++){
  string ProcessesID;
  int timing;
  cin>>timing;

  itoa( i , ProcessesID ,10);

  strncat(Pstring,ProcessesID , Pstring.length()+ProcessesID.length());

  Processes[i] = new process(ProcessesID, timing);


  }




}



class process{
	string processID;
	int BurstTiming;
	string SequenceTiming;
	int EstimatedTime;
	int waitingTime;
	int TurnAroundTime;
	public:

	process(string ID, int Timing){
	this.processID 	= ID;
	this.timing	= Timing;
	}
	  /*
		There is just one constructor
	  */
       process(){
       //Default constructor
       }

       void setET(process *array , int length){
       int min;
       array[0].timing=min;
	for( int i = 0 ; i < length ; i++){

	      array[i].timing=min;
	      for(int j = i ; j < length ; j++){
		if(array[j].timing<min){
			min=array[j];
		}
	      }
	      array[i].EstimatedTime = min;
	}
       }



       void setSequenceOfExecution(process * Array , int length ){
	for(int i = 0; i < length; i++){
		int temp;
		for(int j = 0 ; j < length ; i++){
			if(Array[i].EstimatedTime==Array[j].BurstTiming){
			temp = j;
			break;
			}
		Array[i].sequenceTiming = Array[temp].ProcessID;
		}
	}
       }

       void calculateWaitingTime(process * Array, int length){
		int start = 0 ;
		Array[0].waitingTime=0;
		for( int i =1; i < length; i++){
		     Array[i].waitingTime = Array[i-1].waitingTime+Array[i-1].BurstTime;
		}
       }
	void setTurnAroundTime(process * Array , int length){
		for(int i = 0 ; i < length ; i++){
			Array[i].TurnAroundTime = Array[i].BurstTime+Array[i].WaitingTime;
		}
	}
};