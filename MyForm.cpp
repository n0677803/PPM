#include "MyForm.h"
#include "SongSelect.h"

using namespace System; //Provides functions to work with UI controls
using namespace System::Windows::Forms;
//http://www.bogotobogo.com/cplusplus/application_visual_studio_2013.php
[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project::MyForm form;
	Application::Run(%form);
}

