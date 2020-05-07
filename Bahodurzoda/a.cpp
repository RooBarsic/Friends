
	if(ui->radioButton->isChecked() == true){
		vector<double> buffer;
		buffer.resize(101, 0);

		for(int i = 0; i < 5; i++){
			result.temperature[i].resize(101, 0);
		}

		int errorCode;
		if ((errorCode = MPI_Init(0, 0)) != 0){
			cout << "Ошибка запуска, выполнение остановлено " << endl;
			MPI_Abort(MPI_COMM_WORLD, errorCode);
			return errorCode;
		}
		int myid;
		MPI_Comm_rank(MPI_COMM_WORLD,&myid);  //  получаем в myid - id нащего процесса

		if(myid == 0){
			for(int i = 0; i < 51; i++){
				buffer[i] = 2. * Umax * dx * i;
			}
		} else if(myid == 1){
			for(int i = 51; i < 101; i++){
				buffer[i] = 2. * Umax  - 2. * Umax * dx * i;
			}
		}

		MPI_Reduce(&(*buffer.begin()), &(*result.temperature[0].begin()), 101,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
		MPI_Finalize();
	}
