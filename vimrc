" ================================
"  Basic editor settings
" ================================

set relativenumber
set number
set ruler
syntax on
filetype on
filetype plugin on
filetype indent on

" ================================
"  Indentation / Tabs
" ================================

set expandtab
set tabstop=4
set shiftwidth=4
set softtabstop=4

" Use C-style indentation (more reliable for C/C++)
set cindent
set autoindent

" Adjust C/C++ indent behavior
set cinoptions=:0,l1,g0,t0,(0,W4
    " :0  → No extra indent after case labels
    " l1  → Indent continuation lines by 1 shiftwidth
    " g0  → No indent for C++ scope declarations
    " t0  → No extra indent after function return types
    " (0  → No extra indent for parentheses continuation
    " W4  → Indent wrapped lines by 4 spaces

" Make sure filetype plugins handle C++ properly
autocmd FileType c,cpp,h,hpp setlocal cindent

" ================================
"  Search
" ================================

set hlsearch
set incsearch
set ignorecase
set smartcase

" ================================
"  C++-specific tweaks
" ================================

augroup cpp_filetypes
    autocmd!
    autocmd BufRead,BufNewFile *.h,*.hpp setlocal filetype=cpp
augroup END

autocmd BufNewFile,BufRead *.cpp,*.hpp,*.h syntax on

" ================================
"  Visuals
" ================================

set showmatch
set cursorline
set background=dark
set laststatus=2
set backspace=indent,eol,start
set showcmd

" ================================
"  Multiple windows & file management
" ================================

" Split navigation shortcuts (no need for Ctrl-W before movement)
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l

" Resize splits easily
nnoremap <A-Left>  :vertical resize -2<CR>
nnoremap <A-Right> :vertical resize +2<CR>
nnoremap <A-Up>    :resize -2<CR>
nnoremap <A-Down>  :resize +2<CR>

" Open splits
nnoremap <leader>sv :vsplit<CR>  " Vertical split
nnoremap <leader>sh :split<CR>   " Horizontal split

" Switch buffers (multiple files)
nnoremap <leader>n :bnext<CR>
nnoremap <leader>p :bprevious<CR>

" Quickly close the current split
nnoremap <leader>q :q<CR>

" ================================
"  Quality-of-life
" ================================

" Allow hidden buffers (keep files open in background)
set hidden

" Show all buffers in tabline
set showtabline=2

" Tab navigation (like a browser)
nnoremap <C-Tab>   :tabnext<CR>
nnoremap <C-S-Tab> :tabprevious<CR>

