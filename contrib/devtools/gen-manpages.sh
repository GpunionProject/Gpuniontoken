#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

GPUNIOND=${GPUNIOND:-$SRCDIR/gpuniond}
GPUNIONCLI=${GPUNIONCLI:-$SRCDIR/gpunion-cli}
GPUNIONTX=${GPUNIONTX:-$SRCDIR/gpunion-tx}
GPUNIONQT=${GPUNIONQT:-$SRCDIR/qt/gpunion-qt}

[ ! -x $GPUNIOND ] && echo "$GPUNIOND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
GUTVER=($($GPUNIONCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for gpuniond if --version-string is not set,
# but has different outcomes for gpunion-qt and gpunion-cli.
echo "[COPYRIGHT]" > footer.h2m
$GPUNIOND --version | sed -n '1!p' >> footer.h2m

for cmd in $GPUNIOND $GPUNIONCLI $GPUNIONTX $GPUNIONQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${GUTVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${GUTVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
