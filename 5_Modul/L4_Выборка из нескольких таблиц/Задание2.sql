--Название и продолжительность самого длительного трека.
SELECT name_track, duration 
FROM music_track
ORDER BY duration DESC  
LIMIT 1;

--Название треков, продолжительность которых не менее 3,5 минут.
SELECT name_track, duration 
FROM music_track
WHERE duration > '00:03:30'
ORDER BY duration DESC; 

--Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT name_collection, year_collection 
FROM collection
WHERE year_collection BETWEEN 2018 AND 2020
ORDER BY year_collection DESC;  

--Исполнители, чьё имя состоит из одного слова.
SELECT pseudonym 
FROM singer
WHERE pseudonym NOT LIKE '% %'; 

--Название треков, которые содержат слова «мой» или «my».
SELECT name_track 
FROM music_track
WHERE name_track ILIKE '%my%';