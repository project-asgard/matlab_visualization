#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "MatlabDataArray.hpp"
#include "MatlabEngine.hpp"

int main()
{
  std::vector< std::u16string > names = matlab::engine::findMATLAB();

  if( names.size() != 1 )
  {
    std::cout << "Number of running matlab instances is not 1" << std::endl;

    return 0;
  }

  std::u16string session_name = names[ 0 ];

  std::unique_ptr<matlab::engine::MATLABEngine> m;

  try
  {
    m = matlab::engine::connectMATLAB( session_name );
  }
  catch( const std::exception &e )
  {
    std::cout << e.what() << std::endl;
  }


  // Create matlab data array factory
  matlab::data::ArrayFactory factory;

  // Create data variable
  matlab::data::Array data = factory.createArray<double>
      ({ 1, 5 }, { 4.0, 11.0, 4.7, 36.2, 72.3 });

  // Put data variable in MATLAB global workspace
  m->setVariable(u"data", data, matlab::engine::WorkspaceType::GLOBAL);

  return 0;
}
