so ~/.vim/vim/asc.vim
so ~/.vim/vim/skywind.vim

let g:bundle_group = ['simple', 'basic', 'inter', 'opt', 'ale', 'echodoc']
so ~/.vim/vim/bundle.vim

inoremap ( ()<Left>
inoremap () ()
inoremap (<Esc> (<Esc>
inoremap [ []<Left>
inoremap [] []
inoremap [<Esc> [<Esc>
inoremap { {}<Left>
inoremap {} {}
inoremap {<Esc> {<Esc>
inoremap {<CR> {}<Left><CR><Esc>O
set showmode 
set number
cabbrev E Explore 
set tags=tags;/
noremap <C-k><C-b> :NERDTreeToggle<cr>
