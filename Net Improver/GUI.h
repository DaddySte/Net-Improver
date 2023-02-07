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

		Point offset;
		bool dragging;
	private: System::Windows::Forms::Label^ label1;
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

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ listBox;
	private: System::Windows::Forms::Button^ CreateBackup;
	private: System::ComponentModel::BackgroundWorker^ ThreadBackup;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ ShowTweaks;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ CloseButton;
	private: System::Windows::Forms::Button^ HideButton;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->runAlgorithm = (gcnew System::Windows::Forms::Button());
			this->ThreadOne = (gcnew System::ComponentModel::BackgroundWorker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox = (gcnew System::Windows::Forms::ComboBox());
			this->CreateBackup = (gcnew System::Windows::Forms::Button());
			this->ThreadBackup = (gcnew System::ComponentModel::BackgroundWorker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ShowTweaks = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->HideButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// runAlgorithm
			// 
			this->runAlgorithm->BackColor = System::Drawing::Color::Transparent;
			this->runAlgorithm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->runAlgorithm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->runAlgorithm->ForeColor = System::Drawing::Color::White;
			this->runAlgorithm->Location = System::Drawing::Point(351, 370);
			this->runAlgorithm->Name = L"runAlgorithm";
			this->runAlgorithm->Size = System::Drawing::Size(123, 41);
			this->runAlgorithm->TabIndex = 0;
			this->runAlgorithm->Text = L"Apply Tweaks";
			this->runAlgorithm->UseVisualStyleBackColor = false;
			this->runAlgorithm->Click += gcnew System::EventHandler(this, &GUI::runAlgorithm_Click);
			// 
			// ThreadOne
			// 
			this->ThreadOne->WorkerSupportsCancellation = true;
			this->ThreadOne->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::ThreadOne_DoWork);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(140, 204);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(208, 60);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Select Mode:\r\n1.Default (Windows Default Settings)\r\n2.Optimized (Improved TCP Set"
				L"tings)\r\n3.Gaming (Best TCP Settings)";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// listBox
			// 
			this->listBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->listBox->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->listBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->listBox->ForeColor = System::Drawing::Color::White;
			this->listBox->FormattingEnabled = true;
			this->listBox->ItemHeight = 20;
			this->listBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Default", L"Optimized", L"Gaming" });
			this->listBox->Location = System::Drawing::Point(151, 298);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(190, 28);
			this->listBox->TabIndex = 3;
			// 
			// CreateBackup
			// 
			this->CreateBackup->BackColor = System::Drawing::Color::Transparent;
			this->CreateBackup->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CreateBackup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->CreateBackup->ForeColor = System::Drawing::Color::White;
			this->CreateBackup->Location = System::Drawing::Point(19, 370);
			this->CreateBackup->Name = L"CreateBackup";
			this->CreateBackup->Size = System::Drawing::Size(123, 41);
			this->CreateBackup->TabIndex = 4;
			this->CreateBackup->Text = L"Create Backup";
			this->CreateBackup->UseVisualStyleBackColor = false;
			this->CreateBackup->Click += gcnew System::EventHandler(this, &GUI::CreateBackup_Click);
			// 
			// ThreadBackup
			// 
			this->ThreadBackup->WorkerSupportsCancellation = true;
			this->ThreadBackup->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::ThreadBackup_DoWork);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label3->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->label3->Location = System::Drawing::Point(181, 435);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 15);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Restart Your Computer!";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label3->Visible = false;
			// 
			// ShowTweaks
			// 
			this->ShowTweaks->BackColor = System::Drawing::Color::Transparent;
			this->ShowTweaks->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ShowTweaks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->ShowTweaks->ForeColor = System::Drawing::Color::White;
			this->ShowTweaks->Location = System::Drawing::Point(184, 370);
			this->ShowTweaks->Name = L"ShowTweaks";
			this->ShowTweaks->Size = System::Drawing::Size(123, 41);
			this->ShowTweaks->TabIndex = 6;
			this->ShowTweaks->Text = L"Get Info";
			this->ShowTweaks->UseVisualStyleBackColor = false;
			this->ShowTweaks->Click += gcnew System::EventHandler(this, &GUI::ShowTweaks_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(143, 29);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(205, 152);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// CloseButton
			// 
			this->CloseButton->BackColor = System::Drawing::Color::Transparent;
			this->CloseButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CloseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->CloseButton->ForeColor = System::Drawing::Color::White;
			this->CloseButton->Location = System::Drawing::Point(456, 0);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(37, 22);
			this->CloseButton->TabIndex = 8;
			this->CloseButton->Text = L"X";
			this->CloseButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->CloseButton->UseVisualStyleBackColor = false;
			this->CloseButton->Click += gcnew System::EventHandler(this, &GUI::CloseButton_Click);
			// 
			// HideButton
			// 
			this->HideButton->BackColor = System::Drawing::Color::Transparent;
			this->HideButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HideButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->HideButton->ForeColor = System::Drawing::Color::White;
			this->HideButton->Location = System::Drawing::Point(420, 0);
			this->HideButton->Name = L"HideButton";
			this->HideButton->Size = System::Drawing::Size(37, 22);
			this->HideButton->TabIndex = 9;
			this->HideButton->Text = L"-";
			this->HideButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->HideButton->UseVisualStyleBackColor = false;
			this->HideButton->Click += gcnew System::EventHandler(this, &GUI::HideButton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(-1, 471);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(494, 18);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Powered By Physiological";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(493, 489);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->HideButton);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->ShowTweaks);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->CreateBackup);
			this->Controls->Add(this->listBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->runAlgorithm);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GUI";
			this->Text = L"GUI";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GUI::GUI_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GUI::GUI_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GUI::GUI_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e) {
		hideCMD();
	}


	//Window Movement
	private: System::Void GUI_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void GUI_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = false;
	}

	private: System::Void GUI_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	//Hide & Close
	private: System::Void CloseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Environment::Exit(0);
	}

	private: System::Void HideButton_Click(System::Object^ sender, System::EventArgs^ e) {
		WindowState = FormWindowState::Minimized;
	}

	//Buttons
	private: System::Void CreateBackup_Click(System::Object^ sender, System::EventArgs^ e) {

		if (!ThreadBackup->IsBusy)
		{
			ThreadBackup->RunWorkerAsync();
		}

	}

	private: System::Void ShowTweaks_Click(System::Object^ sender, System::EventArgs^ e) {

		system("start https://github.com/DaddySte/Net-Improver");

	}

	private: System::Void runAlgorithm_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!ThreadOne->IsBusy)
		{
			ThreadOne->RunWorkerAsync();
		}
	}

	public:
		int tweak = 0;

	private: System::Void ThreadOne_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		if (listBox->SelectedItem == "Default" || listBox->SelectedItem == "Optimized" || listBox->SelectedItem == "Gaming") {

			if (listBox->SelectedItem == "Default")
			{
				tweak = 1;
			}

			if (listBox->SelectedItem == "Optimized")
			{
				tweak = 2;
			}

			if (listBox->SelectedItem == "Gaming")
			{
				tweak = 3;
			}

			label1->Text = "Running...";

			runOptimization(tweak);

			label1->Text = "Done!";

			label3->Visible = true;

		}
		else {
			label1->Text = "No Available Mode Selected!";
		}

		Sleep(1000);

		label1->Text = "Powered By Physiological";
	}

	private: System::Void ThreadBackup_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {

		createBackup();

	}
};
}
