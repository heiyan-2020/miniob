#ifndef HYRISE_OTHERSTATEMENT_H
#define HYRISE_OTHERSTATEMENT_H

#include "SQLStatement.h"

namespace hsql {

enum OtherCommand { kSync, kHelp };

struct OtherStatement : SQLStatement {
  OtherStatement(OtherCommand command);
  ~OtherStatement() override;

  OtherCommand command;
};

}  // namespace hsql

#endif
