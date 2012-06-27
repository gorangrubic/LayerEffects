/*============================================================================*/
// 
// Copyright (C) 2008 by Vinnie Falco, this file is part of VFLib.
// 
// Based on SOCI - The C++ Database Access Library:
//   http://soci.sourceforge.net/
// 
// This file is distributed under the following terms:
// 
// Boost Software License - Version 1.0, August 17th, 2003
// 
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
// 
// This file incorporates work covered by the following copyright
// and permission notice:
// 
// Copyright (C) 2004 Maciej Sobczak, Stephen Hutton, Mateusz Loskot,
// Pawel Aleksander Fedorynski, David Courtney, Rafal Bobrowski,
// Julian Taylor, Henning Basold, Ilia Barahovski, Denis Arnaud,
// Daniel Lidstr�m, Matthieu Kermagoret, Artyom Beilis, Cory Bennett,
// Chris Weed, Michael Davidsaver, Jakub Stachowski, Alex Ott, Rainer Bauer,
// Martin Muenstermann, Philip Pemberton, Eli Green, Frederic Chateau,
// Artyom Tonkikh, Roger Orr, Robert Massaioli, Sergey Nikulov,
// Shridhar Daithankar, S�ren Meyer-Eppler, Mario Valesco.
// 
/*============================================================================*/

#ifndef VF_DB_DETAIL_STATEMENT_IMP_VFHEADER
#define VF_DB_DETAIL_STATEMENT_IMP_VFHEADER

namespace db {

namespace detail {

// statement implementation
class statement_imp
  : public ReferenceCountedObject
  , Uncopyable
{
public:
  explicit statement_imp (session& s);
  explicit statement_imp (prepare_temp_type const& prep);
  ~statement_imp ();

  void erase_bindings ();
  void exchange (detail::into_type_ptr const& i);
  void exchange (detail::use_type_ptr const& u);
  void clean_up ();

  void prepare (std::string const& query, bool bRepeatable = true);
  Error execute ();
  bool fetch (Error& error);
  bool got_data () const;

public:
  void do_intos ();
  void pre_use ();
  void do_uses ();
  void post_use ();
  void release_resources ();
  rowid last_insert_rowid ();

public:
  session& m_session;
  sqlite3_stmt* m_stmt;
  std::string m_query;
  bool m_bReady;
  bool m_bGotData;
  bool m_bFirstTime;
  rowid m_last_insert_rowid;

  typedef std::vector <detail::into_type_base*> intos_t;
  typedef std::vector <detail::use_type_base*> uses_t;

  intos_t m_intos;
  uses_t m_uses;
};

}

}

#endif
