//-----------------------------------------------------------------------------
// Copyright (C) 2010 iZsh <izsh at fail0verflow.com>
// Copyright (C) 2011 Gerhard de Koning Gans
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// High frequency iClass support
//-----------------------------------------------------------------------------
#ifndef CMDHFICLASS_H__
#define CMDHFICLASS_H__

#include "common.h"
#include "fileutils.h"
#include "iclass_cmd.h"

int CmdHFiClass(const char *Cmd);

int info_iclass(void);
int read_iclass_csn(bool loop, bool verbose);
void printIclassDumpContents(uint8_t *iclass_dump, uint8_t startblock, uint8_t endblock, size_t filesize);
void HFiClassCalcDivKey(uint8_t *CSN, uint8_t *KEY, uint8_t *div_key, bool elite);

void GenerateMacFrom(uint8_t *CSN, uint8_t *CCNR, bool use_raw, bool use_elite, uint8_t *keys, uint32_t keycnt, iclass_premac_t *list);
void GenerateMacKeyFrom(uint8_t *CSN, uint8_t *CCNR, bool use_raw, bool use_elite, uint8_t *keys, uint32_t keycnt, iclass_prekey_t *list);
void PrintPreCalcMac(uint8_t *keys, uint32_t keycnt, iclass_premac_t *pre_list);
void PrintPreCalc(iclass_prekey_t *list, uint32_t itemcnt);

uint8_t get_pagemap(const picopass_hdr_t *hdr);
bool check_known_default(uint8_t *csn, uint8_t *epurse, uint8_t *rmac, uint8_t *tmac, uint8_t *key);
#endif
