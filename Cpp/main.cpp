#include<iostream>

#include "mpi.h" // header file to use OpenMPI

using namespace std;

int main(int argc, char** argv){

	// Initialize the MPI Environment
	MPI_Init(&argc, &argv);
	
	int num_procs, proc_id;
	
	/*
		While using mpic++ and mpirun to compile and run the OpenMPI programs

		-> Get the size of the Global Communicator from the terminal arguments
		-> Assign individual process id's to the processes started
	*/

	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_id);

	if( proc_id == 0  ){
		cout << "Total number of Processes : " << num_procs << endl;
	}

	cout << "Current process id : " << proc_id << endl;

	MPI_Finalize(); // FInalize MPI Environment

	return 0;
}

/*
	Instructions to Run the program using OpenMPI

	-> Compilation step 
		
		mpic++ <src.cpp> -o <dest>

	-> Execution
		
		mpirun -np <number_of_processes> ./<dest>
*/
