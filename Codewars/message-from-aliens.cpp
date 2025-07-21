// coding challenge: https://www.codewars.com/kata/598980a41e55117d93000015/cpp

#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/* Findings:
   - most important info to me: messages are written backwards and some symbols are seperators (not part of letters)
   - each letter is fixed to a fixed translation
   - only lower-case letters
   - multiple spaces are possible
   - the symbols combinations actually look a bit like the letter that they represent
   - find first letters from given messages manually
   - order alphabet regarding strings and substrings
*/

char seperator[] = { ']', '{', '.', '\'', '}' };
std::vector<std::pair<char, std::string>> alphabetMap= { /* mapdoesn't keep the order*/
    { 'w', "\\/\\/"   }, /* from other test cases */  
    { 'a', "/\\"      },
    { 'b', "]3"       },
  
    { 'q', "()_"      }, /* from other test cases */
    { 'o', "()"       },
    { 'g', "(_,"      }, /* from other test cases */
    { 'c', "("        }, /* substring after strings */
  
    { 'd', "|)"       },
    { 'h', "|-|"      },
    { 'n', "|\\|"     },
    { 'p', "|^"       },
    { 'u', "|_|"      },
    { 'l', "|_"       },
    { 't', "~|~"      },
    { 'm', "|\\/|"    }, /* from other test cases */
    { 'i', "|"        }, /* substring after strings */
  
    { 'e', "[-"       },
    { 'f', "/="       },
    { 'j', "_T"       }, /* from other test cases */
    { 'k', "/<"       },
    { 'r', "/?"       },
    { 's', "_\\~"     },
    { 'v', "\\/"      }, /* from other test cases */
    { 'x', "><"       }, /* from other test cases */
    { 'y', "`/"       },
    { 'z', "~/_"      }, /* from other test cases */
    { ' ', "__"       }
};

std::string decode(const std::string &m)
{
    std::string message = m; /* store message because of const */
  
    /* translate message */
    size_t pos;
    for (const auto& it : alphabetMap)
    {
      pos = message.find(it.second);
      while (pos != std::string::npos) {
        message.replace(pos, it.second.length(), 1, it.first); /* Replace the found substring */
        pos = message.find(it.second, pos + 1); /* Find next occurrence */
      }
    }
  
    /* reverse the message */
    std::reverse(message.begin(), message.end());
  
    /* remove all seperators, seperator is first symbol */
    char seperator = message[0];
    message.erase(std::remove(message.begin(), message.end(), seperator), message.end());
  
    return message;
}
