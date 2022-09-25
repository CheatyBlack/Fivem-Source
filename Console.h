//------------------------------------------------------------------------------
// Console.h: interface for the Console manipulators.
//------------------------------------------------------------------------------

#if !defined( CONSOLE_MANIP_H__INCLUDED )
#define CONSOLE_MANIP_H__INCLUDED

//------------------------------------------------------------------------------

//------------------------------------------------------------------"includes"--
#include <iostream>
#include <iomanip>
#include <windows.h>



nnamespace Executor
{
	void Render()
	{
		auto size = ImGui::GetWindowSize();
		editor.SetReadOnly(false);
		editor.SetShowWhitespaces(false);
		editor.SetPalette(TextEditor::GetDarkPalette());
		ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 1.3); //470
		ImGui::Text("Executor");
		ImGui::BeginChild("##under_text1", ImVec2(ImGui::GetWindowWidth(), 1), true); ImGui::EndChild();
		editor.Render("##Null", ImVec2(size.x - 16, size.y - 110), true);ImGui::Spacing();
		if (ImGui::Button(ICON_FA_CODE" Execute", ImVec2(116, 30)))
		{
			if (resources[selectedResource] == "_cfx_internal")
			{
				MessageBoxA(NULL, "Craete Driver and paste", MB_OK | MB_ICONERROR);
				return;
			}
			else
			{
				
			}
		}	
		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_FILE" Load from File", ImVec2(180, 30)))
		{
			// load file code
		}
			
		ImGui::SameLine();
		ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
		ImGui::Combo("##resources", &selectedResource, resources.data(), resources.size());
		ImGui::PopItemWidth();
				
	}
}


namespace JadedHoboConsole
{
    static const WORD bgMask( BACKGROUND_BLUE      | 
                              BACKGROUND_GREEN     | 
                              BACKGROUND_RED       | 
                              BACKGROUND_INTENSITY   );
    static const WORD fgMask( FOREGROUND_BLUE      | 
                              FOREGROUND_GREEN     | 
                              FOREGROUND_RED       | 
                              FOREGROUND_INTENSITY   );
    
    static const WORD bgLoCyan   ( bgLoGreen   | bgLoBlue ); 
    static const WORD bgLoMagenta( bgLoRed     | bgLoBlue ); 
    static const WORD bgLoYellow ( bgLoRed     | bgLoGreen ); 
    static const WORD bgLoWhite  ( bgLoRed     | bgLoGreen | bgLoBlue ); 
    static const WORD bgGray     ( bgBlack     | BACKGROUND_INTENSITY ); 
    static const WORD bgHiWhite  ( bgLoWhite   | BACKGROUND_INTENSITY ); 
    static const WORD bgHiBlue   ( bgLoBlue    | BACKGROUND_INTENSITY ); 
    static const WORD bgHiGreen  ( bgLoGreen   | BACKGROUND_INTENSITY ); 
    static const WORD bgHiRed    ( bgLoRed     | BACKGROUND_INTENSITY ); 
    static const WORD bgHiCyan   ( bgLoCyan    | BACKGROUND_INTENSITY ); 
    static const WORD bgHiMagenta( bgLoMagenta | BACKGROUND_INTENSITY ); 
    static const WORD bgHiYellow ( bgLoYellow  | BACKGROUND_INTENSITY );
    
    
    static class con_dev
    {
        private:
        HANDLE                      hCon;
        DWORD                       cCharsWritten; 
        CONSOLE_SCREEN_BUFFER_INFO  csbi; 
        DWORD                       dwConSize;

        public:
        con_dev() 
        { 
            hCon = GetStdHandle( STD_OUTPUT_HANDLE );
        }
        private:
        void GetInfo()
        {
            GetConsoleScreenBufferInfo( hCon, &csbi );
            dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
        }
        public:
        void Clear()
        {
            COORD coordScreen = { 0, 0 };
            
            GetInfo(); 
            FillConsoleOutputCharacter( hCon, ' ',
                                        dwConSize, 
                                        coordScreen,
                                        &cCharsWritten ); 
            GetInfo(); 
            FillConsoleOutputAttribute( hCon,
                                        csbi.wAttributes,
                                        dwConSize,
                                        coordScreen,
                                        &cCharsWritten ); 
            SetConsoleCursorPosition( hCon, coordScreen ); 
        }
        void SetColor( WORD wRGBI, WORD Mask )
        {
            GetInfo();
            csbi.wAttributes &= Mask; 
            csbi.wAttributes |= wRGBI; 
            SetConsoleTextAttribute( hCon, csbi.wAttributes );
        }
    } console;
    
    //narrow manipulators
    inline std::ostream& clr( std::ostream& os )
    {
        os.flush();
        console.Clear();
        return os;
    };
    
    inline std::ostream& fg_red( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgHiRed, bgMask );
        
        return os;
    }
    
    inline std::ostream& fg_green( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgHiGreen, bgMask );
        
        return os;
    }
    
    inline std::ostream& fg_blue( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgHiBlue, bgMask );
        
        return os;
    }
    
    inline std::ostream& fg_white( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgHiWhite, bgMask );
        
        return os;
    }
    
    inline std::ostream& fg_cyan( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgHiCyan, bgMask );
        
        return os;
    }
          }
        public:
        void Clear()
        {
            COORD coordScreen = { 0, 0 };
		{
		   
		   
void c_weapon_replacer::replace_pistol(uint64_t hash) {
	auto pistol = c_mem::get()->read_mem<uintptr_t>(g::base_address.modBaseAddr + 0x027DB7F0);
	if (pistol) {
		pistol = c_mem::get()->read_mem<uintptr_t>(pistol + 0x128);
		if (pistol)
			c_mem::get()->write_mem<uint64_t>(pistol + 0x10, hash);
	}
	
        return os;
    }
    
    inline std::ostream& fg_yellow( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgHiYellow, bgMask );
        
        return os;
    }
    
    inline std::ostream& fg_black( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgBlack, bgMask );
        
        return os;
    }
    
    inline std::ostream& fg_gray( std::ostream& os )
    {
        os.flush();
        console.SetColor( fgGray, bgMask );
        
        return os;
    }
    
    inline std::ostream& bg_red( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiRed, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_green( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiGreen, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_blue( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiBlue, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_white( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiWhite, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_cyan( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiCyan, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_magenta( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiMagenta, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_yellow( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiYellow, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_black( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgBlack, fgMask );
        
        return os;
    }
    
    inline std::ostream& bg_gray( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgGray, fgMask );
        
        return os;
    }
    
    //wide manipulators
    inline std::wostream& clr( std::wostream& os )
    {
        os.flush();
        console.Clear();
        return os;
    };
    
    inline std::wostream& fg_red( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgHiRed, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_green( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgHiGreen, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_blue( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgHiBlue, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_white( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgHiWhite, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_cyan( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgHiCyan, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_magenta( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgHiMagenta, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_yellow( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgHiYellow, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_black( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgBlack, bgMask );
        
        return os;
    }
    
    inline std::wostream& fg_gray( std::wostream& os )
    {
        os.flush();
        console.SetColor( fgGray, bgMask );
        
        return os;
    }
    
    inline std::wostream& bg_red( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgHiRed, fgMask );
        
        return os;
    }
    
    inline std::wostream& bg_green( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgHiGreen, fgMask );
        
        return os;
    }
    
    inline std::wostream& bg_blue( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgHiBlue, fgMask );
        
        return os;
    }
    
    inline std::wostream& bg_white( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgHiWhite, fgMask );
        
        return os;
    }
        inline std::ostream& bg_blue( std::ostream& os )
    {
        os.flush();
        console.SetColor( bgHiBlue, fgMask );
        
        return os;
    }
    inline std::wostream& bg_cyan( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgHiCyan, fgMask );
        
        return os;
    }
    
    inline std::wostream& bg_magenta( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgHiMagenta, fgMask );
        
        return os;
    }
    
    inline std::wostream& bg_yellow( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgHiYellow, fgMask );
        
        return os;
    }
    
    inline std::wostream& bg_black( std::wostream& os )
    {
        os.flush();
        console.SetColor( bgBlack, fgMask );
        
        return os;
    }
   
private:
	fwRefContainer<NetPipe> m_pipe;

	Buffer m_savedFirst;

	bool m_tickTock;

public:
	ConcatOutputPipe(const fwRefContainer<NetPipe>& p1);

	inline fwRefContainer<NetPipe> GetTargetPipe()
	{
		return m_pipe;
	}

	virtual void Reset() override;

	virtual void PassPacket(Buffer data) override;
};

		
		namespace Executor
{
	void Render()
	{
		auto size = ImGui::GetWindowSize();
		editor.SetReadOnly(false);
		editor.SetShowWhitespaces(false);
		editor.SetPalette(TextEditor::GetDarkPalette());
		ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 1.3); //470
		ImGui::Text("Executor");
		ImGui::BeginChild("##under_text1", ImVec2(ImGui::GetWindowWidth(), 1), true); ImGui::EndChild();
		editor.Render("##Null", ImVec2(size.x - 16, size.y - 110), true);ImGui::Spacing();
		if (ImGui::Button(ICON_FA_CODE" Execute", ImVec2(116, 30)))
		{
			if (resources[selectedResource] == "_cfx_internal")
			{
				MessageBoxA(NULL, "You can't execute in _cfx_interal", "redENGINE", MB_OK | MB_ICONERROR);
				return;
			}
			else
			{
				
			}
		}	

		
			DWORD64 WINAPI GetModuleA(_In_opt_ LPCSTR lpModuleName) {
		DWORD ModuleNameLength = (DWORD)strlen(lpModuleName) + 1;

		////allocate buffer for the string on the stack:
		DWORD NewBufferSize = sizeof(wchar_t) * ModuleNameLength;
		wchar_t* W_ModuleName = (wchar_t*)alloca(NewBufferSize);
		for (DWORD i = 0; i < ModuleNameLength; i++)
			W_ModuleName[i] = lpModuleName[i];

		HMODULE hReturnModule = GetModuleW(W_ModuleName);

		RtlSecureZeroMemory(W_ModuleName, NewBufferSize);
		return (DWORD64)hReturnModule;

	}
}
			
