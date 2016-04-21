#include "MyFileSplitter.h"
#include <string>
#include <iostream>

class MainForm : public Form, public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;

	ProgressBar* progressBar;
    ISplitMethod* md;
	SplitterFactory* fa;
public:
	
	MainForm(SplitterFactory*  factory){
        this->fa=factory;
    }
	
	void Button1_Click(){

		std::string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		md= fa->CreateSplitter();

		ConsoleNotifier cn;

		FileSplitter splitter(filePath, number,md);

		splitter.addIProgress(this); //订阅通知
		splitter.addIProgress(&cn); //订阅通知

		splitter.split();

		splitter.removeIProgress(this);

	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};

class ConsoleNotifier : public IProgress {
public:
	virtual void DoProgress(float value){
		std::cout << ".";
	}
};