let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/repos/msfs
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
edit include/msfs/msramfs/msramfs.hpp
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 31 + 106) / 212)
exe '2resize ' . ((&lines * 27 + 28) / 57)
exe 'vert 2resize ' . ((&columns * 90 + 106) / 212)
exe '3resize ' . ((&lines * 26 + 28) / 57)
exe 'vert 3resize ' . ((&columns * 90 + 106) / 212)
exe 'vert 4resize ' . ((&columns * 89 + 106) / 212)
argglobal
enew
file NERD_tree_1
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
wincmd w
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 43 - ((20 * winheight(0) + 13) / 27)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
43
normal! 022|
wincmd w
argglobal
if bufexists("include/msfs/return_codes.hpp") | buffer include/msfs/return_codes.hpp | else | edit include/msfs/return_codes.hpp | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 24 - ((20 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
24
normal! 04|
wincmd w
argglobal
if bufexists("source/filesystem.cpp") | buffer source/filesystem.cpp | else | edit source/filesystem.cpp | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 46 - ((36 * winheight(0) + 27) / 54)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
46
normal! 073|
wincmd w
4wincmd w
exe 'vert 1resize ' . ((&columns * 31 + 106) / 212)
exe '2resize ' . ((&lines * 27 + 28) / 57)
exe 'vert 2resize ' . ((&columns * 90 + 106) / 212)
exe '3resize ' . ((&lines * 26 + 28) / 57)
exe 'vert 3resize ' . ((&columns * 90 + 106) / 212)
exe 'vert 4resize ' . ((&columns * 89 + 106) / 212)
tabnext 1
badd +66 tests/ut/fs/stubs/BlockDeviceDriverStub.hpp
badd +37 .gitignore
badd +16 tests/ut/fs/MsRamFsTests.cpp
badd +50 include/msfs/msramfs/msramfs.hpp
badd +53 include/msfs/filesystem.hpp
badd +27 source/filesystem.cpp
badd +37 include/msfs/block_device.hpp
badd +43 source/block_device.cpp
badd +4 include/msfs/return_codes.hpp
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOSc
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
