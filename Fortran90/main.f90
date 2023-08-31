program main
implicit none

include 'mpif.h' !-- Header file

    integer :: num_proc, proc_id, err

    call MPI_Init(err) !-- Initialize the MPI Environment

    call MPI_Comm_size(MPI_Comm_world, num_proc, err)
    call MPI_Comm_rank(MPI_Comm_world, proc_id, err)

    if(proc_id == 0)then
        write(*,*) 'Total processes running : ', num_proc
    endif

    write(*,*) 'Current Process id : ', proc_id

    call MPI_Finalize(err) !-- FInalize the MPI Environment


end program main



!-- Instructions to run the program using OpenMPI
!-- 1) Compilation step

!--     mpif90 <src.f90> -o <dest>

!-- 2) Execution step

!--     mpirun -np <number_of_processes> ./<dest>
