# New ports collection makefile for:	mt32emu-smf2wav
# Date created:		2016-10-23
# Whom:			sergm <sergm@muntemu.org>
#
# $FreeBSD$
#

PORTNAME=	mt32emu-smf2wav
PORTVERSION=	1.2.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/munt/munt/archive/
FETCH_ARGS=	-a
DISTFILES=	munt_2_0_0.tar.gz

MAINTAINER=	sergm@muntemu.org
COMMENT=	Experimental program for converting SMF (Standard MIDI File) to WAVE via libmt32emu

USES=		cmake
USE_GNOME=	glib20

LIB_DEPENDS=    libmt32emu.so.2:${PORTSDIR}/audio/libmt32emu

PLIST_FILES=	bin/mt32emu-smf2wav \
		share/doc/munt/smf2wav/AUTHORS.txt \
		share/doc/munt/smf2wav/COPYING.txt \
		share/doc/munt/smf2wav/README.txt

PLIST_DIRS=	share/doc/munt/smf2wav \
		share/doc/munt

CMAKE_BUILD_TYPE?=	Release

post-extract:
		mkdir $(WRKSRC)

do-configure:
		cd $(WRKSRC); \
		cmake -D CMAKE_BUILD_TYPE:STRING=$(CMAKE_BUILD_TYPE) $(WRKDIR)/munt-munt_2_0_0/mt32emu_smf2wav

.include <bsd.port.mk>
