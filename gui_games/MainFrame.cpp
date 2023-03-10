#include "MainFrame.h"

enum IDs
{
	First_button = 0,
	Second_button = 1,
	Third_button = 2,
	Nickname_button = 3
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(First_button, MainFrame::OnButtonClickedSnake)
	EVT_BUTTON(Second_button, MainFrame::OnButtonClickedTicTacToe)
	EVT_BUTTON(Third_button, MainFrame::OnButtonClickedDices)
	EVT_BUTTON(Nickname_button, MainFrame::SetUserNickname)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(900, 600));
	panel->SetBackgroundColour(wxColor(80, 80, 150));

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Set your nickname:", wxPoint(395, 200)); // statyczny tekstkna::
	text_to_copy = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 225), wxSize(200, -1));
	wxButton* Nick_button = new wxButton(panel, Nickname_button, "OK", wxPoint(395, 265), wxSize(100, 30)); // add przycisk

	Nick_button->SetCursor(wxCursor(wxCURSOR_HAND));

};

void MainFrame::SetUserNickname(wxCommandEvent& event)
{
	nickname = text_to_copy->GetValue().ToStdString();
	text_to_copy->Destroy();
	panel->Destroy();

	panel = new wxPanel(this); // newwin
	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);
	wxBitmap SnakeIMG, TicIMG, DicesIMG;
	SnakeIMG.LoadFile("snake.png", wxBITMAP_TYPE_PNG);
	DicesIMG.LoadFile("dices.png", wxBITMAP_TYPE_PNG);
	TicIMG.LoadFile("tictactoe.png", wxBITMAP_TYPE_PNG);

	wxBitmapButton* SnakeButton = new wxBitmapButton(panel, First_button, SnakeIMG, wxPoint(0, 0), wxSize(300, 800), 0);
	wxBitmapButton* TicTacToeButton = new wxBitmapButton(panel, Second_button, TicIMG, wxPoint(300, 0), wxSize(300, 800), 0);
	wxBitmapButton* DicesButton = new wxBitmapButton(panel, Third_button, DicesIMG, wxPoint(600, 0), wxSize(300, 800), 0);

	SnakeButton->SetCursor(wxCursor(wxCURSOR_HAND));
	TicTacToeButton->SetCursor(wxCursor(wxCURSOR_HAND));
	DicesButton->SetCursor(wxCursor(wxCURSOR_HAND));

	//wxButton* SnakeButton = new wxButton(panel, First_button, "Snake", wxPoint(200, 200), wxSize(100, 30)); // add przycisk
	//wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "tekst i chuj", wxPoint(70, 30)); // statyczny tekst
	//wxTextCtrl *textCtrl = new wxTextCtrl(panel, wxID_ANY, "nickname", wxPoint(500, 145), wxSize(200, -1)); // mozliwosc wpisania tekstu do ramki

	CreateStatusBar();
}

void MainFrame::OnButtonClickedSnake(wxCommandEvent& event)
{
	panel->Destroy();
	panel= new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(900, 600));

	wxPNGHandler *handler = new wxPNGHandler;
	wxImage::AddHandler(handler);
	wxStaticBitmap *snake_board = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("snake_board.png", wxBITMAP_TYPE_PNG), wxPoint(50, 50), wxSize(500, 500));
	panel->SetBackgroundColour(wxColor(80, 80, 150));


	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "tekst", wxPoint(600, 50)); // statyczny tekst
	wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, nickname, wxPoint(600, 10)); // statyczny tekst

	wxLogStatus("Snake and ladders");
}

void MainFrame::OnButtonClickedTicTacToe(wxCommandEvent& event){
	TicTacToe* tictactoe = new TicTacToe("TicTacToe", nickname);
	tictactoe->SetClientSize(900, 600);
	tictactoe->Center();
	tictactoe->Show();
}

void MainFrame::OnButtonClickedDices(wxCommandEvent& event){
	Dices* dices = new Dices("Dices", nickname);
	dices->SetClientSize(900, 600);
	dices->Center();
	dices->Show();

	/*panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(900, 600));

	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);
	wxBitmap DicesIMG;
	DicesIMG.LoadFile("dices_board.png", wxBITMAP_TYPE_PNG);
	wxBitmapButton* SnakeButton = new wxBitmapButton(panel, First_button, DicesIMG, wxPoint(50, 50), wxSize(300, 500), 0);

	wxButton* SnakeButton2 = new wxButton(panel, wxID_ANY, "Snake", wxPoint(200, 200), wxSize(100, 30)); // add przycisk
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "tekst", wxPoint(70, 30)); // statyczny tekst
	//wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "nickname", wxPoint(500, 145), wxSize(200, -1)); // mozliwosc wpisania tekstu do ramki

	wxLogStatus("Dices");
	*/
}