// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 1 "grammar.y"

#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>

#line 47 "Parser.cpp"


#include "Parser.hpp"


// Unqualified %code blocks.
#line 26 "grammar.y"

    #include "InputScanner.hpp"
    #define yylex(x) scanner->lex(x)
#line 46 "grammar.y"

    namespace calculator {
        long long ivars['Z' - 'A' + 1];
        double fvars['z' - 'a' + 1];
    } 

#line 65 "Parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "grammar.y"
namespace calculator {
#line 138 "Parser.cpp"


  /// Build a parser object.
  Parser::Parser (Scanner* scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        value.move< char > (std::move (that.value));
        break;

      case 4: // FLT
      case 17: // fexp
        value.move< double > (std::move (that.value));
        break;

      case 3: // INT
      case 16: // iexp
        value.move< long long > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        value.copy< char > (YY_MOVE (that.value));
        break;

      case 4: // FLT
      case 17: // fexp
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 3: // INT
      case 16: // iexp
        value.copy< long long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        value.move< char > (YY_MOVE (s.value));
        break;

      case 4: // FLT
      case 17: // fexp
        value.move< double > (YY_MOVE (s.value));
        break;

      case 3: // INT
      case 16: // iexp
        value.move< long long > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case 4: // FLT
      case 17: // fexp
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 3: // INT
      case 16: // iexp
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case 4: // FLT
      case 17: // fexp
        value.move< double > (YY_MOVE (that.value));
        break;

      case 3: // INT
      case 16: // iexp
        value.move< long long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        value.copy< char > (that.value);
        break;

      case 4: // FLT
      case 17: // fexp
        value.copy< double > (that.value);
        break;

      case 3: // INT
      case 16: // iexp
        value.copy< long long > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        value.move< char > (that.value);
        break;

      case 4: // FLT
      case 17: // fexp
        value.move< double > (that.value);
        break;

      case 3: // INT
      case 16: // iexp
        value.move< long long > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 5: // INTVAR
      case 6: // FLTVAR
        yylhs.value.emplace< char > ();
        break;

      case 4: // FLT
      case 17: // fexp
        yylhs.value.emplace< double > ();
        break;

      case 3: // INT
      case 16: // iexp
        yylhs.value.emplace< long long > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4:
#line 59 "grammar.y"
                                    { std::cerr << "Ingrese una expresión.\n"; }
#line 721 "Parser.cpp"
    break;

  case 5:
#line 60 "grammar.y"
                                    { std::cout << "Resultado:" << yystack_[1].value.as < long long > () << '\n'; }
#line 727 "Parser.cpp"
    break;

  case 6:
#line 61 "grammar.y"
                                    { std::cout << "Resultado:" << yystack_[1].value.as < double > () << '\n'; }
#line 733 "Parser.cpp"
    break;

  case 7:
#line 62 "grammar.y"
                                    { ivars[yystack_[3].value.as < char > () - 'A'] = yystack_[1].value.as < long long > (); }
#line 739 "Parser.cpp"
    break;

  case 8:
#line 63 "grammar.y"
                                    { fvars[yystack_[3].value.as < char > () - 'a'] = yystack_[1].value.as < double > (); }
#line 745 "Parser.cpp"
    break;

  case 9:
#line 64 "grammar.y"
                                    { yyerrok; }
#line 751 "Parser.cpp"
    break;

  case 10:
#line 67 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[0].value.as < long long > (); }
#line 757 "Parser.cpp"
    break;

  case 11:
#line 68 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () + yystack_[0].value.as < long long > (); }
#line 763 "Parser.cpp"
    break;

  case 12:
#line 69 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () - yystack_[0].value.as < long long > (); }
#line 769 "Parser.cpp"
    break;

  case 13:
#line 70 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () * yystack_[0].value.as < long long > (); }
#line 775 "Parser.cpp"
    break;

  case 14:
#line 71 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () / yystack_[0].value.as < long long > (); }
#line 781 "Parser.cpp"
    break;

  case 15:
#line 72 "grammar.y"
                                    { yylhs.value.as < long long > () = pow(yystack_[2].value.as < long long > (), yystack_[0].value.as < long long > ()); }
#line 787 "Parser.cpp"
    break;

  case 16:
#line 73 "grammar.y"
                                    { yylhs.value.as < long long > () = -yystack_[0].value.as < long long > (); }
#line 793 "Parser.cpp"
    break;

  case 17:
#line 74 "grammar.y"
                                    { yylhs.value.as < long long > () = ivars[yystack_[0].value.as < char > () - 'A']; }
#line 799 "Parser.cpp"
    break;

  case 18:
#line 77 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 805 "Parser.cpp"
    break;

  case 19:
#line 78 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () + (double)yystack_[0].value.as < long long > (); }
#line 811 "Parser.cpp"
    break;

  case 20:
#line 79 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () - (double)yystack_[0].value.as < long long > (); }
#line 817 "Parser.cpp"
    break;

  case 21:
#line 80 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () * (double)yystack_[0].value.as < long long > (); }
#line 823 "Parser.cpp"
    break;

  case 22:
#line 81 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () / ((double)yystack_[0].value.as < long long > ()); }
#line 829 "Parser.cpp"
    break;

  case 23:
#line 82 "grammar.y"
                                    { yylhs.value.as < double > () = pow(yystack_[2].value.as < double > (), yystack_[0].value.as < long long > ()); }
#line 835 "Parser.cpp"
    break;

  case 24:
#line 83 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 841 "Parser.cpp"
    break;

  case 25:
#line 84 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 847 "Parser.cpp"
    break;

  case 26:
#line 85 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 853 "Parser.cpp"
    break;

  case 27:
#line 86 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 859 "Parser.cpp"
    break;

  case 28:
#line 87 "grammar.y"
                                    { yylhs.value.as < double > () = pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 865 "Parser.cpp"
    break;

  case 29:
#line 88 "grammar.y"
                                    { yylhs.value.as < double > () = (double)yystack_[2].value.as < long long > () + yystack_[0].value.as < double > (); }
#line 871 "Parser.cpp"
    break;

  case 30:
#line 89 "grammar.y"
                                    { yylhs.value.as < double > () = (double)yystack_[2].value.as < long long > () - yystack_[0].value.as < double > (); }
#line 877 "Parser.cpp"
    break;

  case 31:
#line 90 "grammar.y"
                                    { yylhs.value.as < double > () = (double)yystack_[2].value.as < long long > () * yystack_[0].value.as < double > (); }
#line 883 "Parser.cpp"
    break;

  case 32:
#line 91 "grammar.y"
                                    { yylhs.value.as < double > () = (double)yystack_[2].value.as < long long > () / yystack_[0].value.as < double > (); }
#line 889 "Parser.cpp"
    break;

  case 33:
#line 92 "grammar.y"
                                    { yylhs.value.as < double > () = pow((double)yystack_[2].value.as < long long > (), yystack_[0].value.as < double > ()); }
#line 895 "Parser.cpp"
    break;

  case 34:
#line 93 "grammar.y"
                                    { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 901 "Parser.cpp"
    break;

  case 35:
#line 94 "grammar.y"
                                    { yylhs.value.as < double > () = fvars[yystack_[0].value.as < char > () - 'a']; }
#line 907 "Parser.cpp"
    break;


#line 911 "Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -10;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -10,    54,   -10,     0,   -10,   -10,     1,     2,   -10,    -2,
      56,    62,   -10,   -10,    22,    -2,   -10,   -10,    -3,     3,
     -10,    -2,    -2,    -2,    -2,    -2,   -10,    -2,    -2,    -2,
      -2,    -2,    22,    68,    80,    74,    17,    84,    17,    84,
      -3,     3,    -3,     3,    -3,     3,    17,    84,    17,    84,
      -3,     3,    -3,     3,    -3,     3,    12,   -10,    22,    22,
      22,    22,    22,   -10,    88,    88,    12,    12,    12
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     1,     0,    10,    18,    17,    35,     4,     0,
       0,     0,     3,     9,     0,     0,    17,    35,    16,    34,
       5,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    29,    12,    30,
      13,    31,    14,    32,    15,    33,    19,    24,    20,    25,
      21,    26,    22,    27,    23,    28,    16,     7,     0,     0,
       0,     0,     0,     8,    11,    12,    13,    14,    15
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -10,    -9,    15,   -10,   -10
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    10,    11,     1,    12
  };

  const signed char
  Parser::yytable_[] =
  {
      18,     4,     5,    16,    17,    33,    34,    13,     9,    14,
      15,    25,    36,    38,    40,    42,    44,    31,    46,    48,
      50,    52,    54,    56,    19,     4,    62,    16,    23,    24,
      35,    25,    32,     0,     0,     0,    37,    39,    41,    43,
      45,     0,    47,    49,    51,    53,    55,     0,     0,    64,
      65,    66,    67,    68,     2,     3,     0,     4,     5,     6,
       7,     8,     0,    20,     9,    21,    22,    23,    24,    26,
      25,    27,    28,    29,    30,    57,    31,    58,    59,    60,
      61,    63,    62,    27,    28,    29,    30,     0,    31,    21,
      22,    23,    24,     0,    25,    29,    30,     0,    31,    60,
      61,     0,    62
  };

  const signed char
  Parser::yycheck_[] =
  {
       9,     3,     4,     5,     6,    14,    15,     7,    10,     8,
       8,    14,    21,    22,    23,    24,    25,    14,    27,    28,
      29,    30,    31,    32,     9,     3,    14,     5,    11,    12,
      15,    14,    10,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    58,
      59,    60,    61,    62,     0,     1,    -1,     3,     4,     5,
       6,     7,    -1,     7,    10,     9,    10,    11,    12,     7,
      14,     9,    10,    11,    12,     7,    14,     9,    10,    11,
      12,     7,    14,     9,    10,    11,    12,    -1,    14,     9,
      10,    11,    12,    -1,    14,    11,    12,    -1,    14,    11,
      12,    -1,    14
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    18,     0,     1,     3,     4,     5,     6,     7,    10,
      16,    17,    19,     7,     8,     8,     5,     6,    16,    17,
       7,     9,    10,    11,    12,    14,     7,     9,    10,    11,
      12,    14,    10,    16,    16,    17,    16,    17,    16,    17,
      16,    17,    16,    17,    16,    17,    16,    17,    16,    17,
      16,    17,    16,    17,    16,    17,    16,     7,     9,    10,
      11,    12,    14,     7,    16,    16,    16,    16,    16
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    15,    18,    18,    19,    19,    19,    19,    19,    19,
      16,    16,    16,    16,    16,    16,    16,    16,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     2,     4,     4,     2,
       1,     3,     3,     3,     3,     3,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "INT", "FLT", "INTVAR", "FLTVAR", "EOL",
  "ASSIGN", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "UMINUS", "EXPONENT",
  "$accept", "iexp", "fexp", "lines", "line", YY_NULLPTR
  };


  const signed char
  Parser::yyrline_[] =
  {
       0,    55,    55,    56,    59,    60,    61,    62,    63,    64,
      67,    68,    69,    70,    71,    72,    73,    74,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
    };
    const int user_token_number_max_ = 269;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 14 "grammar.y"
} // calculator
#line 1290 "Parser.cpp"

#line 97 "grammar.y"

 
void calculator::Parser::error(const std::string& msg) {
    std::cerr << "Algo ocurrió." << msg << '\n';
}
