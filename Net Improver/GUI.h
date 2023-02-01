#pragma once
#include "TCPImprove.h"

namespace NetImprover {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Riepilogo per GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ runAlgorithm;
	private: System::ComponentModel::BackgroundWorker^ ThreadOne;
	private: System::Windows::Forms::Label^ label1;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variabile di progettazione necessaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necessario per il supporto della finestra di progettazione. Non modificare
		/// il contenuto del metodo con l'editor di codice.
		/// </summary>
		void InitializeComponent(void)
		{
			this->runAlgorithm = (gcnew System::Windows::Forms::Button());
			this->ThreadOne = (gcnew System::ComponentModel::BackgroundWorker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// runAlgorithm
			// 
			this->runAlgorithm->Location = System::Drawing::Point(76, 152);
			this->runAlgorithm->Name = L"runAlgorithm";
			this->runAlgorithm->Size = System::Drawing::Size(75, 23);
			this->runAlgorithm->TabIndex = 0;
			this->runAlgorithm->Text = L"Run";
			this->runAlgorithm->UseVisualStyleBackColor = true;
			this->runAlgorithm->Click += gcnew System::EventHandler(this, &GUI::runAlgorithm_Click);
			// 
			// ThreadOne
			// 
			this->ThreadOne->WorkerSupportsCancellation = true;
			this->ThreadOne->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::ThreadOne_DoWork);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(88, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->runAlgorithm);
			this->Name = L"GUI";
			this->Text = L"GUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void runAlgorithm_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!ThreadOne->IsBusy) {
			ThreadOne->RunWorkerAsync();
		}
	}
	private: System::Void ThreadOne_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		label1->Text = "Running...";
		runOptimization(3);
		label1->Text = "Done";
	}
	};
}
