/*****************************************************************************
 *  __________________    _________  _____            _____  .__         ._.
 *  \______   \______ \  /   _____/ /     \          /  _  \ |__| ____   | |
 *   |    |  _/|    |  \ \_____  \ /  \ /  \        /  /_\  \|  _/ __ \  | |
 *   |    |   \|    `   \/        /    Y    \      /    |    |  \  ___/   \|
 *   |______  /_______  /_______  \____|__  / /\   \____|__  |__|\___ |   __
 *          \/        \/        \/        \/  )/           \/        \/   \/
 *
 * This file is part of liBDSM. Copyright © 2014-2015 VideoLabs SAS
 *
 * Author: Julien 'Lta' BALLET <contact@lta.io>
 *
 * liBDSM is released under LGPLv2.1 (or later) and is also available
 * under a commercial license.
 *****************************************************************************
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/**
 * @file smb_defs.h
 * @brief SMB usefull constants
 */

#ifndef _SMB_DEFS_H_
#define _SMB_DEFS_H_

#include "bdsm/smb_defs.h"

//-----------------------------------------------------------------------------/
// Our own identity
//-----------------------------------------------------------------------------/
#define SMB_OS                  "Unix"
#define SMB_LANMAN              "liBDSM"


//-----------------------------------------------------------------------------/
// A few magic stuffs (SMB magic // our dialect support)
//-----------------------------------------------------------------------------/
#define SMB_MAGIC               { 0xff, 0x53, 0x4d, 0x42 } // aka "\xffSMB"
#define SMB_DIALECTS {          \
  "\2Samba",                    \
  "\2NT LM 0.12",               \
  NULL                          \
}
// Dialect values must match position on SMB_DIALECTS array
#define SMB_DIALECT_SAMBA       0
#define SMB_DIALECT_NTLM        1


//-----------------------------------------------------------------------------/
// SMB Operations/Commands
//-----------------------------------------------------------------------------/
#define SMB_CMD_CLOSE           0x04
#define SMD_CMD_TRANS           0x25
#define SMB_CMD_TRANS2          0x32
#define SMB_CMD_TREE_DISCONNECT 0x71
#define SMB_CMD_NEGOTIATE       0x72
#define SMB_CMD_SETUP           0x73 // Session Setup AndX
#define SMB_CMD_TREE_CONNECT    0x75 // Tree Connect AndX
#define SMB_CMD_ECHO            0x2b
#define SMB_CMD_READ            0x2e // Read AndX
#define SMB_CMD_CREATE          0xa2 // NT Create AndX


//-----------------------------------------------------------------------------/
// SMB TRANS2 SubCommands
//-----------------------------------------------------------------------------/
#define SMB_TR2_FIND_FIRST      0x0001
#define SMB_TR2_QUERY_PATH      0x0005


//-----------------------------------------------------------------------------/
// NTSTATUS Codes
//-----------------------------------------------------------------------------/
#define NT_STATUS_SUCCESS                   0x00000000
#define NT_STATUS_MORE_PROCESSING_REQUIRED  0xc0000016
#define NT_STATUS_ACCESS_DENIED             0xc0000022


///////////////////////////////////////////////////////////////////////////////
//// Flags definitions
//// Many aren't use in libdsm but are here for possible later use

// Protocol negotiation flags (flags field in spec)
#define SMB_FLAG_RESPONSE       (1 << 7)
#define SMB_FLAG_NOTIFY         (1 << 6)
#define SMB_FLAG_OPLOCK         (1 << 5)
#define SMB_FLAG_CANONIC        (1 << 4)
#define SMB_FLAG_CASELESS       (1 << 3)
#define SMB_FLAG_BUFFER_POSTED  (1 << 1)
#define SMB_FLAG_LOCK_AND_READ  (1 << 0)
// More Protocol negotiation flags (flags2 field in spec)
#define SMB_FLAG_UNICODE        (1 << (15 + 8))
#define SMB_FLAG_NT_ERRORS      (1 << (14 + 8))
#define SMB_FLAG_EXECUTE_ONLY   (1 << (13 + 8))
#define SMB_FLAG_DFS            (1 << (12 + 8))
#define SMB_FLAG_XSEC           (1 << (11 + 8))
#define SMB_FLAG_REPARSE_PATH   (1 << (10 + 8))
#define SMB_FLAG_LONG_NAMES     (1 << (6 + 8))
#define SMB_FLAG_SIGN_REQUIRED  (1 << (4 + 8))
#define SMB_FLAG_COMPRESSED     (1 << (3 + 8))
#define SMB_FLAG_SIGN_SUPPORT   (1 << (2 + 8))
#define SMB_FLAG_EXT_ATTR       (1 << (1 + 8))
#define SMB_FLAG_LONG_NAMES_OK  (1 << (0 + 8))

// Negotiated server capabilities
#define SMB_CAPS_RAW            (1 << 0)
#define SMB_CAPS_MPX            (1 << 1)
#define SMB_CAPS_UNICODE        (1 << 2)
#define SMB_CAPS_LARGE          (1 << 3)
#define SMB_CAPS_NTSMB          (1 << 4)
#define SMB_CAPS_RPC            (1 << 5)
#define SMB_CAPS_NTFIND         (1 << 9)
#define SMB_CAPS_XSEC           (1 << 31)

// File creation/open flags
#define SMB_CREATE_OPLOCK       (1 << 1)
#define SMB_CREATE_BATCH_OPLOCK (1 << 2)
#define SMB_CREATE_MKDIR        (1 << 3)
#define SMB_CREATE_EXT_RESP     (1 << 4)
#define SMB_CREATE_DEFAULTS     (0)


// File attributes
#define SMB_ATTR_RO             (1 << 0)
#define SMB_ATTR_HIDDEN         (1 << 1)
#define SMB_ATTR_SYS            (1 << 2)
#define SMB_ATTR_VOLID          (1 << 3)  // Volume ID
#define SMB_ATTR_DIR            (1 << 4)
#define SMB_ATTR_ARCHIVE        (1 << 5)  // Modified since last archive (!?)
#define SMB_ATTR_DEVICE         (1 << 6)
#define SMB_ATTR_NORMAL         (1 << 7)
#define SMB_ATTR_TEMP           (1 << 8)
#define SMB_ATTR_SPARSE         (1 << 9)
#define SMB_ATTR_REPARSE_PT     (1 << 10)
#define SMB_ATTR_COMPRESSED     (1 << 11)
#define SMB_ATTR_OFFLINE        (1 << 12)
#define SMB_ATTR_INDEXED        (1 << 13) // Not set = May be indexed
#define SMB_ATTR_ENCRYPTED      (1 << 14)
// Share access flags
#define SMB_SHARE_READ          (1 << 0)
#define SMB_SHARE_WRITE         (1 << 1)
#define SMB_SHARE_DELETE        (1 << 2)

// Trans 2 flags
//// Find First 2
#define SMB_FIND2_ATTR_RO       (1 << 0)  // Include RO files in result
#define SMB_FIND2_ATTR_HIDDEN   (1 << 1)  // Include hidden files
#define SMB_FIND2_ATTR_SYSTEM   (1 << 2)  // Include system files
#define SMB_FIND2_ATTR_VOLUME   (1 << 3)  // Include volume ID ?
#define SMB_FIND2_ATTR_DIR      (1 << 4)  // Include directory ?
#define SMB_FIND2_ATTR_ARCHIVE  (1 << 5)  // Include archive ?
#define SMB_FIND2_ATTR_DEFAULT  (SMB_FIND2_ATTR_RO | SMB_FIND2_ATTR_HIDDEN |  \
                                 SMB_FIND2_ATTR_SYSTEM | SMB_FIND2_ATTR_DIR)

#define SMB_FIND2_FLAG_CLOSE      (1 << 0)  // Close search after request ?
#define SMB_FIND2_FLAG_CLOSE_EOS  (1 << 1)  // Close after End Of Search ?
#define SMB_FIND2_FLAG_RESUME     (1 << 2)  // Send resume keys ?
#define SMB_FIND2_FLAG_CONTINUE   (1 << 3)  // not set == new search
#define SMB_FIND2_FLAG_BACKUP     (1 << 3)  // Backup intent ?
#define SMB_FIND2_FLAG_DEFAULT    (SMB_FIND2_FLAG_CLOSE_EOS | \
                                   SMB_FIND2_FLAG_RESUME)

#endif
