/**
 * @file ssreg.h
 * @brief CSRegistry windows registry functionality wrapper...
 * @author Simon Steele
 * @note Copyright (c) 2002 Simon Steele <s.steele@pnotepad.org>
 *
 * Programmers Notepad 2 : The license file (license.[txt|html]) describes 
 * the conditions under which this source may be modified / distributed.
 */

#ifndef __SSREG_H__
#define __SSREG_H__

#include "stdafx.h"

namespace ssreg
{

class CSRegistry
{
	private:
		bool m_open;
		HKEY m_hKey;
		HKEY m_root;
	public:
		CSRegistry() : m_open(false), m_hKey(NULL), m_root(HKEY_CURRENT_USER){};
		~CSRegistry();
		bool OpenKey(LPCTSTR key, bool bCreate=true);
		void CloseKey();

		void WriteInt(LPCTSTR valname, int value);
		int ReadInt(LPCTSTR valname, int defaultval = 0);

		void WriteString(LPCTSTR valname, LPCTSTR value);
		bool ReadString(LPCTSTR valname, ctcString& value);

		void WriteBool(LPCTSTR valname, bool value);
		bool ReadBool(LPCTSTR valname, bool defaultval = false);

		bool SetRootKey(HKEY root){m_root = root;};
};

}

#endif