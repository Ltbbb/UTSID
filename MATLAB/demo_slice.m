% --- Executes on button press in butMatch.
function butMatch_Callback(hObject, eventdata, handles)
% hObject    handle to butMatch (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
sigma = 5;
if isempty(handles.img_tpl_veins)
    [region,edgs] = lee_region(handles.img_tpl, 4, 40);
    [handles.img_tpl,region] = huang_normalise(handles.img_tpl,region,edgs);
    tmp = miura_max_curvature(handles.img_tpl,region,sigma);
    handles.img_tpl_veins = binarize(tmp,'median');
end
[region,edgs] = lee_region(handles.img_cap, 4, 40);
[handles.img_cap,region] = huang_normalise(handles.img_cap,region,edgs);
tmp = miura_max_curvature(handles.img_cap,region,sigma);
handles.img_cap_veins = binarize(tmp,'median');

score = miura_match(double(handles.img_tpl_veins), double(handles.img_cap_veins),50,100);
fprintf('Match score: %3.2f%%\n', score*200);