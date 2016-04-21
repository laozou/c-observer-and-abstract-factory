#include <string>
#include <list>
#include "SplitterMethod_Factory.h"


class IProgress{
public:
	virtual void DoProgress(float value)=0;
	virtual ~IProgress(){}
};


class FileSplitter
{
	std::string m_filePath;
	int m_fileNumber;
	ISplitMethod* m_imethod;

	std::list<IProgress*>  m_iprogressList; // ����֪ͨ���ƣ�֧�ֶ���۲���
	
public:
	FileSplitter(const std::string& filePath, int fileNumber, ISplitMethod* imethod)
		: m_filePath(filePath), m_fileNumber(fileNumber), m_imethod(imethod)
	{

	}


	void split(){

		//1.��ȡ���ļ�

		//2.��������С�ļ���д��
		for (int i = 0; i < m_fileNumber; i++){
			m_imethod->Split(m_filePath, m_fileNumber);

			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);//����֪ͨ
		}

	}


	void addIProgress(IProgress* iprogress){
		m_iprogressList.push_back(iprogress);
	}

	void removeIProgress(IProgress* iprogress){
		m_iprogressList.remove(iprogress);
	}


protected:
	virtual void onProgress(float value){
		
		std::list<IProgress*>::iterator itor=m_iprogressList.begin();

		while (itor != m_iprogressList.end() )
			(*itor)->DoProgress(value); //���½�����
			itor++;
		}
	}
};