filetype indent on

set number
set ruler

syntax on

"Customize backspace
set backspace=eol,start,indent
"set whichwrap+=<,>,h,1

"set cursorline
set shiftwidth=4
set tabstop=4 softtabstop=4
set expandtab
set smartindent
set smartcase
set noerrorbells
set autoindent

"incremental search
set incsearch

"allows custom vimrc files in specific directories
set exrc



set nowrap
set showmode
set showmatch

set hlsearch
"turns off highlight after search is done
set nohlsearch

"keeps projects in the buffer for saving
set hidden

"starts scrolling down when 8 lines away
"set scrolloff=8

"mouse support
set mouse=a

"code folding
set foldmethod=indent
set foldlevelstart=99

"color schemes
set background=dark
colorscheme delek

:map <Left> h
:map! <Left> <Left>
:map <Right> l
:map! <Right> <Right>
:map <Up> k
:map! <Up> <Up>
:map <Down> j
:map! <Down> <Down>

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" MULTIPURPOSE TAB KEY
" Indent if we're at the beginning of a line. Else, do completion.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
function! InsertTabWrapper()
    let col = col('.') - 1
    if !col || getline('.')[col - 1] !~ '\k'
        return "\<tab>"
    else
        return "\<c-p>"
    endif
endfunction
inoremap <expr> <tab> InsertTabWrapper()
inoremap <s-tab> <c-n>
