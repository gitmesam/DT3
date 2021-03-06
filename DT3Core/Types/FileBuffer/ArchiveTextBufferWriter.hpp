#pragma once
#ifndef DT3_ARCHIVETEXTBUFFERWRITER
#define DT3_ARCHIVETEXTBUFFERWRITER
//==============================================================================
///
///	File: ArchiveTextBufferWriter.hpp
///
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///
//==============================================================================

#include "DT3Core/Types/FileBuffer/Archive.hpp"
#include "DT3Core/Types/FileBuffer/TextBufferStream.hpp"

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Forward declarations
//==============================================================================

//==============================================================================
/// Class
//==============================================================================

class ArchiveTextBufferWriter: public Archive {
    public:
        DEFINE_TYPE(ArchiveTextBufferWriter,Archive)
        DEFINE_CREATE

                                    ArchiveTextBufferWriter		(void);

    private:
                                    ArchiveTextBufferWriter		(const ArchiveTextBufferWriter &rhs);
        ArchiveTextBufferWriter &   operator =                  (const ArchiveTextBufferWriter &rhs);

    public:
        virtual                     ~ArchiveTextBufferWriter	(void);

    public:

        /// Streams data into or out of this object
        /// \param data data to stream
        /// \return this archiving object so you can chain them together
        virtual Archive &           operator <<                 (const ArchiveData& data);

        /// Adds a sub domain for the archive
        /// \param domain name of the domain
        virtual void                push_domain                 (const std::string &domain);

        /// Balances the sub domain for the archive
        virtual void                pop_domain                  (void);

        /// Returns wether the archive is reading or not
        /// \return archive is loading
        DTboolean                   is_reading                  (void) const;

        /// Returns wether the arcive is writing or not
        /// \return archive is saving
        DTboolean                   is_writing                  (void) const;

        /// Returns the stream
        /// \return stream
        TextBufferStream&           stream                      (void)		{	return _buffer;	}

    private:
        std::string					indent                      (void) const;

        DTint                       _indent;
        TextBufferStream            _buffer;

};

//==============================================================================
//==============================================================================

} // DT3

#endif
