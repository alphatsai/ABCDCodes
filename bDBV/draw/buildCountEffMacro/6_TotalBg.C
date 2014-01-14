	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== Total Background MC ==////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;

	Bg_1_Eff	= Bg_1_RestNum/Bg_TotalEvt;
	Bg_12_Eff   	= Bg_12_RestNum/Bg_1_RestNum;
	Bg_123_Eff     	= Bg_123_RestNum/Bg_12_RestNum;
	Bg_1234_Eff   	= Bg_1234_RestNum/Bg_123_RestNum;
	Bg_12345_Eff   	= Bg_12345_RestNum/Bg_1234_RestNum;
//	Bg_123456_Eff 	= Bg_123456_RestNum/Bg_12345_RestNum;
//	Bg_Total_Eff	= Bg_123456_RestNum/Bg_TotalEvt;
	Bg_Total_Eff	= Bg_12345_RestNum/Bg_TotalEvt;

	cout<<"Selection Cut\t\t"	<<"Efficiency"		<<endl;
	cout<<"Good CA8>=1\t\t"		<<Bg_1_Eff		<<endl;
	cout<<"Good 2b CA8>=1\t\t"	<<Bg_12_Eff		<<endl;
	cout<<"Good AK5>=2\t\t"		<<Bg_123_Eff		<<endl;
	cout<<"Good CSVM AK5>=2\t"	<<Bg_1234_Eff		<<endl;
	cout<<"Ht(AK5CA8)>1000\t\t"	<<Bg_12345_Eff		<<endl;
	cout<<"Total\t\t\t"		<<Bg_Total_Eff		<<endl;
	cout<<endl;

}
