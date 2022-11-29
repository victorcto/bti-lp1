#ifndef TEST_HPP
#define TEST_HPP
#include "Autocorrect.hpp"
#include "Autocomplete.hpp"
#include "Interface.hpp"

class Test
{
private:
  Autocomplete* autocomplete;
  Autocorrect* autocorrect;
  Interface* interface;
public:
  /**
   * @brief Construtor personalizado da classe com uma referência para Autocomplete e Autocorrect.
   * @param autocomplete referência para o Autocomplete.
   * @param autocorrect referência para o Autocorrect.
   * @param interface referência para a Interface.
   */
  Test(Autocomplete* autocomplete, Autocorrect* autocorrect, Interface* interface);

  /**
   * @brief Método que irá testar a aplicação com base nos arquivos de validação contidos no
   * diretório /tests e a fonte de dados especificada.
   */
  void testApplication();
};

#endif