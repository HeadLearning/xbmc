#ifndef _ENCODERFLAC_H
#define _ENCODERFLAC_H

/*
 *      Copyright (C) 2005-2008 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 51 Franklin Street, Suite 500, Boston, MA 02110, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "Encoder.h"
#include "DllFlacEnc.h"

class CEncoderFlac : public CEncoder
{
public:
  CEncoderFlac();
  virtual ~CEncoderFlac();
  bool Init(const char* strFile, int iInChannels, int iInRate, int iInBits);
  int Encode(int nNumBytesRead, uint8_t* pbtStream);
  bool Close();

private:
  DllFlacEnc m_dll;
  FLAC__StreamEncoder *m_encoder;
  FLAC__StreamMetadata *m_metadata[2];

  static const int SAMPLES_BUF_SIZE = 1024 * 2;
  FLAC__int32 *m_samplesBuf;

  static FLAC__StreamEncoderWriteStatus write_callback(const FLAC__StreamEncoder *encoder, const FLAC__byte buffer[], size_t bytes, unsigned samples, unsigned current_frame, void *client_data);
};

#endif // _ENCODERFLAC_H
