#include <stdlib.h>

#include <stdio.h>

#include <stdint.h>

#include <string.h>

#include <ctype.h>

#include <time.h>

void command_help(uint8_t * n, uint8_t * d, uint8_t * o);
typedef struct Command Command;
Command get_command(int32_t argc, uint8_t ** argv);
typedef struct vec_u8 vec_u8;
typedef struct vec_T vec_T;
vec_u8 vec_u8_new(int32_t cap);
typedef struct vec_parser_Expr vec_parser_Expr;
void gen_generate_vector(vec_parser_Expr ast);
typedef struct lexer_Token lexer_Token;
typedef struct vec_lexer_Token vec_lexer_Token;
vec_lexer_Token lexer_lex();
typedef struct vec_T vec_T;
vec_lexer_Token vec_lexer_Token_new(int32_t cap);
int32_t main(int32_t argc, uint8_t ** argv);
typedef struct vec_lexer_Token vec_lexer_Token;
typedef struct vec_parser_Expr vec_parser_Expr;
uint8_t * get_option(int32_t * index, int32_t argc, uint8_t ** argv);
typedef struct Color Color;
void set_color(Color color);
typedef struct parser_Expr parser_Expr;
typedef struct vec_parser_Expr vec_parser_Expr;
typedef struct vec_lexer_Token vec_lexer_Token;
vec_parser_Expr parser_parse(vec_lexer_Token tokens);
typedef struct vec_T vec_T;
vec_parser_Expr vec_parser_Expr_new(int32_t cap);
struct vec_u8 {
  u8 * buf;
  int32_t size;
  int32_t cap;
};
vec_u8 vec_u8_new(int32_t cap) {
  return (vec_u8) {
    mem_alloc(mem_size_u8() * cap), 0, cap,
  };
};
struct vec_parser_Expr {
  parser_Expr * buf;
  int32_t size;
  int32_t cap;
};
struct vec_lexer_Token {
  lexer_Token * buf;
  int32_t size;
  int32_t cap;
};
vec_lexer_Token vec_lexer_Token_new(int32_t cap) {
  return (vec_lexer_Token) {
    mem_alloc(mem_size_lexer_Token() * cap), 0, cap,
  };
};
struct vec_lexer_Token {
  lexer_Token * buf;
  int32_t size;
  int32_t cap;
};
struct vec_parser_Expr {
  parser_Expr * buf;
  int32_t size;
  int32_t cap;
};
struct vec_parser_Expr {
  parser_Expr * buf;
  int32_t size;
  int32_t cap;
};
struct vec_lexer_Token {
  lexer_Token * buf;
  int32_t size;
  int32_t cap;
};
vec_parser_Expr vec_parser_Expr_new(int32_t cap) {
  return (vec_parser_Expr) {
    mem_alloc(mem_size_parser_Expr() * cap), 0, cap,
  };
};
void command_help(uint8_t * n, uint8_t * d, uint8_t * o) {
  printf(d);
  printf("\n\nUSAGE:\n    cup ");
  printf(n);
  printf(" [OPTIONS]\n\nOPTIONS:");
  printf(o);
  printf("\n");
};
uint8_t * command_options_empty = "\n    No options are available for this command";
uint8_t * command_options_compile = (((("\n    -i, --input     Specify the input file name"
        "\n    -o, --output    Specify the output file name")
      "\n    -cg, --gcc     Use GCC as a compiler")
    "\n    -cm, --msvc    Use MSVC as a compiler")
  "\n    -cc, --clang   use Clang as a compiler")
"\n    -ct, --tcc     Use TinyCC as a compiler";
union CommandUnion {
  char _;
};
struct Command {
  int type;
  union CommandUnion u;
};
Command get_command(int32_t argc, uint8_t ** argv) {
  if (argc == 1) {
    return (Command) {
      0
    };
  }
  uint8_t is_command = 0;
  vec_u8 vector = vec_u8_new(16);
  for (int i = 1; i < argc; i += 1) {
    if (i == 4) {
      break l;
    }
    if (((argv[i])[0]) == '-') {
      if (is_command) {
        break l;
      }
      continue l;
    }
    is_command = 1;
    int32_t length = strlen(argv[i]);
    for (int c = 0; c < length; c += 1) {
      vector.push((argv[i])[c]);
    }
  }
  vector.push('\0');
  uint8_t * input = vector.buf;
  if (strcmp(input, "help") == 0) {
    return (Command) {
      1
    };
  } else if (strcmp(input, "helprun") == 0) {
    return (Command) {
      2
    };
  } else if (strcmp(input, "helpbuild") == 0) {
    return (Command) {
      3
    };
  } else if (strcmp(input, "helpcheck") == 0) {
    return (Command) {
      4
    };
  } else if (strcmp(input, "helpupdate") == 0) {
    return (Command) {
      6
    };
  } else if (strcmp(input, "helpadd") == 0) {
    return (Command) {
      7
    };
  } else if (strcmp(input, "helpremove") == 0) {
    return (Command) {
      8
    };
  } else if (strcmp(input, "helpgendocs") == 0) {
    return (Command) {
      9
    };
  } else if (strcmp(input, "helpgenbinds") == 0) {
    return (Command) {
      10
    };
  } else if (strcmp(input, "helpselfupdate") == 0) {
    return (Command) {
      11
    };
  } else if (strcmp(input, "helpselfinstall") == 0) {
    return (Command) {
      12
    };
  } else if (strcmp(input, "helpselfuninstall") == 0) {
    return (Command) {
      13
    };
  } else if (strcmp(input, "run") == 0) {
    return (Command) {
      14
    };
  } else if (strcmp(input, "build") == 0) {
    return (Command) {
      15
    };
  } else if (strcmp(input, "check") == 0) {
    return (Command) {
      16
    };
  } else if (strcmp(input, "update") == 0) {
    return (Command) {
      18
    };
  } else if (strcmp(input, "add") == 0) {
    return (Command) {
      19
    };
  } else if (strcmp(input, "remove") == 0) {
    return (Command) {
      20
    };
  } else if (strcmp(input, "gendocs") == 0) {
    return (Command) {
      21
    };
  } else if (strcmp(input, "genbinds") == 0) {
    return (Command) {
      22
    };
  } else if (strcmp(input, "selfupdate") == 0) {
    return (Command) {
      23
    };
  } else if (strcmp(input, "selfinstall") == 0) {
    return (Command) {
      24
    };
  } else if (strcmp(input, "selfuninstall") == 0) {
    return (Command) {
      25
    };
  }
  return (Command) {
    0
  };
};
void gen_generate_vector(vec_parser_Expr ast) {};
struct lexer_Token {};
vec_lexer_Token lexer_lex() {
  return vec_lexer_Token_new(1);
};
uint8_t * file_name = (void * ) 0;
int32_t file_size;
int32_t main(int32_t argc, uint8_t ** argv) {
  Command command = get_command(argc, argv);
  if ((argc == 1) || (command == (Command) {
      1
    })) {
    printf("Cup Toolkit v0.0.1\n\n");
    printf("USAGE:\n    cup [COMMAND] [OPTIONS]");
    printf("\n\nCOMMANDS:");
    printf("\n    run                  Compile and run the current package");
    printf("\n    build                Compile the current package");
    printf("\n    check                Analyze the current package");
    printf("\n    new [PACKAGE]        Create a new package");
    printf("\n    update [PACKAGE]     Update given dependency");
    printf("\n    add [PACKAGE]        Adds given dependency");
    printf("\n    remove [PACKAGE]     Removes given dependency");
    printf("\n    gen docs             Generate documentation for the current package");
    printf("\n    gen binds [HEADER]   Generate bindings for a given C header file");
    printf("\n    self update          Update the Cup Toolkit");
    printf("\n    self install         Install the Cup Toolkit");
    printf("\n    self uninstall       Uninstall the Cup Toolkit");
    printf("\n\nSee 'cup help [COMMAND]' for more info about a specific command and it's available options.\n");
    return 0;
  } else if (command == (Command) {
      0
    }) {
    set_color((Color) {
      1
    });
    printf("error: ");
    set_color((Color) {
      0
    });
    printf("no such command: '%s", argv[1]);
    for (int i = 2; i < argc; i += 1) {
      printf(" %s", argv[i]);
    }
    printf("'\n\nSee 'cup help' for the list of available commands.\n");
    return 1;
  }
  switch (command.type) {
  case 14:
    break m;
    break;
  case 15:
    break m;
    break;
  case 16:
    return 1;
    break;
  case 17:
    return 1;
    break;
  case 18:
    return 1;
    break;
  case 19:
    return 1;
    break;
  case 20:
    return 1;
    break;
  case 21:
    return 1;
    break;
  case 22:
    return 1;
    break;
  case 23:
    return 1;
    break;
  case 24:
    return 1;
    break;
  case 25:
    return 1;
    break;
  case 2:
    command_help("run", "Compile and run the current package", command_options_compile);
    return 0;
    break;
  case 3:
    command_help("build", "Compile the current package", command_options_compile);
    return 0;
    break;
  case 4:
    command_help("check", "Analyze the current package", command_options_empty);
    return 0;
    break;
  case 5:
    command_help("new", "Create a new package", command_options_empty);
    return 0;
    break;
  case 6:
    command_help("update", "Update given dependency", command_options_empty);
    return 0;
    break;
  case 7:
    command_help("add", "Adds given dependency", command_options_empty);
    return 0;
    break;
  case 8:
    command_help("remove", "Removes given dependency", command_options_empty);
    return 0;
    break;
  case 9:
    command_help("gen docs", "Generate documentation for the current package", command_options_empty);
    return 0;
    break;
  case 10:
    command_help("gen binds", "Generate bindings for a given C header file", command_options_empty);
    return 0;
    break;
  case 11:
    command_help("self update", "Update the Cup Toolkit", command_options_empty);
    return 0;
    break;
  case 12:
    command_help("self install", "Install the Cup Toolkit", command_options_empty);
    return 0;
    break;
  case 13:
    command_help("self uninstall", "Uninstall the Cup Toolkite", command_options_empty);
    return 0;
    break;
  }
  uint8_t * output = (void * ) 0;
  for (int i = 2; i < argc; i += 1) {
    if (((argv[i])[0]) == '-') {} else {
      set_color((Color) {
        1
      });
      printf("error: ");
      set_color((Color) {
        0
      });
      printf("invalid option '%s'", argv[i]);
    }
  }
  FILE * file_point;
  if (fopen_s(( & file_point), file_name, "rb")) {
    set_color((Color) {
      1
    });
    printf("error: ");
    set_color((Color) {
      0
    });
    printf("no such file or directory: '%s'", file_name);
    return 1;
  }
  fseek(file_point, (int32_t) 0, SEEK_END);
  file_size = ftell(file_point);
  rewind(file_point);
  uint8_t * file = mem_alloc(file_size);
  fread(file, file_size, 1, file_point);
  fclose(file_point);
  vec_lexer_Token tokens = lexer_lex();
  vec_parser_Expr ast = parser_parse(tokens);
  if (output != (void * ) 0) {
    fopen_s(( & file_point), output, "w");
  } else {
    fopen_s(( & file_point), "out.c", "w");
  }
  fputs("#include <stdint.h>\n", file_point);
  gen_generate_vector(ast);
  fclose(file_point);
  system("cc test/test0/out.c -o test/test0/out");
  printf("Compilation successful (%.3lfs elapsed)\n", (double) clock());
  return 0;
};
uint8_t * get_option(int32_t * index, int32_t argc, uint8_t ** argv) {
  if (strlen(argv[( * index)]) > 2) {
    return (argv[( * index)]) + 1;
  } else if (argc > ( * index)) {
    return argv[(( * index) += 1)];
  }
  return (void * ) 0;
};
union ColorUnion {
  char _;
};
struct Color {
  int type;
  union ColorUnion u;
};
void set_color(Color color) {};
struct parser_Expr {};
vec_parser_Expr parser_parse(vec_lexer_Token tokens) {
  return vec_parser_Expr_new(1);
};