#include "MyForm.cpp"
#include <iostream>
#include <string>
#include "note.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Note not(1, "123", "contetn");
	form::MyForm form(&not);
	Application::Run(% form);
}