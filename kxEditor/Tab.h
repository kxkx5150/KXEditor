﻿#pragma once
#include "Tabs.h"
#include <windows.h>

class EditView;
class Tab;
class TextEditor;
class LinkedList;
class DocMgr;
class WebView;
class WebMgr;

class Tab {
    HWND m_hwnd;
    HWND m_txthWnd;
    HWND m_webhwnd;

public:
    TextEditor* m_txteditr = nullptr;
    EditView* m_editview = nullptr;
    LinkedList* m_Document = nullptr;
    DocMgr* m_docmgr = nullptr;
    WebView* m_webeditr = nullptr;
    WebMgr* m_webmgr = nullptr;

    BOOL m_is_txt = true;

private:
    int m_tabid = 0;

    int m_width = 0;
    int m_height = 0;
    int m_x = 0;
    int m_y = 0;

public:
    Tab(HWND hWnd, HWND txthwnd, TextEditor* txtee, EditView* editview, HWND whWnd, WebView* webview, int tabid);
    ~Tab();

    LONG create();
    LONG create_file(TCHAR* szFileName = nullptr);
    LONG init_file();
    LONG create_emptyfile();
    LONG OpenFile(TCHAR* szFileName);
    void close_document();
    void resize_view(HDWP hdwp, int width, int height, int x, int y);
    void change_webview();
    void change_txtview();
    void change_view();
    void resize_webview();

};