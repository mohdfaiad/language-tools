/**
 * Exemplo de método que faz a leitura do arquivo xml e seta
 * as strings do idioma selecionado nos componentes da interface
 * 
 * Os nós do xml são localizados pelo nome do componente na interface, facilitando o parse do arquivo.
 */

void TForm1::SetLanguage(UnicodeString lang)
{

   	char CurrentPath[_MAX_PATH];

	getcwd(CurrentPath, _MAX_PATH);

	UnicodeString filename = CurrentPath;

	if(lang=="pt")	{

		filename = filename + "\\Languages\\Portuguese.lang";
		Portugs1->Checked = true;
		English1->Checked = false;

	}else if(lang=="en")
	{
		filename = filename + "\\Languages\\English.lang";
		Portugs1->Checked = false;
		English1->Checked = true;
	}

	if(FileExists(filename))
	{
		_di_IXMLDocument doc;
		doc = LoadXMLDocument(filename);
		doc->Active = true;

		_di_IXMLNode node = doc->ChildNodes->Nodes["Language"];

		//altera o idioma dos forms
		m_lang->SetLanguage(node);

		//altera o idioma do main
		_di_IXMLNode myNode = node->ChildNodes->Nodes[File1->Name];
		File1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Newproject1->Name];
		Newproject1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Openproject1->Name];
		Openproject1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[SaveProject1->Name];
		SaveProject1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[SaveProjectas1->Name];
		SaveProjectas1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Import1->Name];
		Import1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Export1->Name];
		Export1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Edit1->Name];
		Edit1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Tools1->Name];
		Tools1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[L1->Name];
		L1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[English1->Name];
		English1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Portugs1->Name];
		Portugs1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Help1->Name];
		Help1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Aboutlanguagetools1->Name];
		Aboutlanguagetools1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[EditCut1->Name];
		EditCut1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[EditCopy1->Name];
		EditCopy1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[EditPaste1->Name];
		EditPaste1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[FileExit1->Name];
		FileExit1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[addDfm->Name];
		addDfm->Caption = myNode->Text;
	}
}
