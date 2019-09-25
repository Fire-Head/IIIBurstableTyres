/***************************************************************************
 *                                                                         *
 * Module  : rperror.h                                                     *
 *                                                                         *
 * Purpose : Used to generate error codes                                  *
 *                                                                         *
 **************************************************************************/

#ifndef RPERROR_H
#define RPERROR_H

/****************************************************************************
 Includes
 */

#include "rpplugin.h"

/****************************************************************************
 Defines
 */

#define RWECODE(a,b) a,

#define RWCONCAT(_A,_B) _A ## _B
#define _PLUGIN_ERRENUM(_X) RWCONCAT(_,_X)

#define RW_PLUGIN_ERRENUM _PLUGIN_ERRENUM(rwPLUGIN_ERRENUM)

enum RW_PLUGIN_ERRENUM
{
#include "rperror.def"
    rwPLUGIN_ERRENUMLAST = RWFORCEENUMSIZEINT
};

typedef enum RW_PLUGIN_ERRENUM rwPLUGIN_ERRENUM;

#endif /* RPERROR_H */
