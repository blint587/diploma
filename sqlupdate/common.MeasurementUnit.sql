SET NOCOUNT ON
 
SET IDENTITY_INSERT [common].[MeasurementUnit] ON
 
MERGE INTO [common].[MeasurementUnit] AS Target
USING (VALUES
  (1,'meter','m','m',1.000000000000000e+000,0.000000000000000e+000,0,1,'ohdp')
 ,(2,'gram','g','g',1.000000000000000e+000,0.000000000000000e+000,1,1,'ohdp')
 ,(3,'second', 's','s',1.000000000000000e+000,0.000000000000000e+000,2,1,'ohdp')
 ,(4,'ampere', 'A','A',1.000000000000000e+000,0.000000000000000e+000,3,1,'ohdp')
 ,(5,'kelvin', 'K','K',1.000000000000000e+000,0.000000000000000e+000,4,1,'ohdp')
 ,(6,'mol', 'mol','mol',1.000000000000000e+000,0.000000000000000e+000,5,1,'ohdp')
 ,(7,'candelas', 'cd','cd',1.000000000000000e+000,0.000000000000000e+000,6,1,'ohdp')
 ,(8,'inch', 'inc','inc',2.540000000000000e-002,0.000000000000000e+000,0,1,'ohdp')
 ,(9,'feet', 'ft','ft',3.048000000000000e-001,0.000000000000000e+000,0,1,'ohdp')
 ,(10,'mile', 'mi','mi',1.609344000000000e+003,0.000000000000000e+000,0,1,'ohdp')
 ,(11,'yard', 'yd','yd',9.140000000000000e-001,0.000000000000000e+000,0,1,'ohdp')
 ,(12,'ounce', 'oz','oz',2.834950000000000e+001,0.000000000000000e+000,1,1,'ohdp')
 ,(13,'pound', 'lb','lb',4.535920000000000e+002,0.000000000000000e+000,1,1,'ohdp')
 ,(14,'metric ton', 't','t',1.000000000000000e+006,0.000000000000000e+000,1,1,'ohdp')
 ,(15,'slug', 'slug','slug',1.459390300000000e+004,0.000000000000000e+000,1,1,'ohdp')
 ,(16,'minute','min','min',6.000000000000000e+001,0.000000000000000e+000,2,1,'ohdp')
 ,(17,'hour', 'h','h',3.600000000000000e+003,0.000000000000000e+000,2,1,'ohdp')
 ,(18,'day', 'd','d',8.640000000000000e+004,0.000000000000000e+000,2,1,'ohdp')
 ,(19,'celsius', '°C','°C',1.000000000000000e+000,2.731500000000000e+002,4,1,'ohdp')
 ,(20,'fahrenheit', '°F','°F',5.555555555555555e-001,4.596700000000000e+002,4,1,'ohdp')
 ,(21,'m2', 'm2','m2',1.000000000000000e+000,0.000000000000000e+000,7,1,'ohdp')
 ,(22,'m3', 'm3','m3',1.000000000000000e+000,0.000000000000000e+000,8,1,'ohdp')
 ,(23,'liter', 'l','l',1.000000000000000e-003,0.000000000000000e+000,8,1,'ohdp')
 ,(24,'US gallon', 'gal','gal',3.785411780000000e-003,0.000000000000000e+000,8,1,'ohdp')
 ,(25,'m3 s-1', 'm3 s-1','m3 s-1',NULL,NULL,9,1,'ohdp')
 ,(26,'CFM', 'CFM','ft3 min-1',NULL,NULL,9,1,'ohdp')
 ,(27,'MLD', 'MLD','Ml d-1',NULL,NULL,9,1,'ohdp')
 ,(28,'m3 d-1', 'm3 d-1','m3 d-1',NULL,NULL,9,1,'ohdp')
 ,(29,'m3 h-1', 'm3 h-1','m3 h-1',NULL,NULL,9,1,'ohdp')
 ,(30,'m3 min-1', 'm3 min-1','m3 min-1',NULL,NULL,9,1,'ohdp')
 ,(31,'l s-1', 'l s-1','l s-1',NULL,NULL,9,1,'ohdp')
 ,(32,'l min-1', 'l min-1','l min-1',NULL,NULL,9,1,'ohdp')
 ,(33,'mol m-3', 'mol m-3','mol m-3',NULL,NULL,10,1,'ohdp')
 ,(34,'m s-2', 'm s-2','m s-2',NULL,NULL,11,1,'ohdp')
 ,(35,'newton', 'N','kg m s-2',NULL,NULL,12,1,'ohdp')
 ,(36,'lbf', 'lbf','slug ft s-2',NULL,NULL,12,1,'ohdp')
 ,(37,'dyn', 'dyn','g cm s-2',NULL,NULL,12,1,'ohdp')
 ,(38,'m s-1', 'm s-1','m s-1',NULL,NULL,13,1,'ohdp')
 ,(39,'km h-1', 'km h-1','km h-1',NULL,NULL,13,1,'ohdp')
 ,(40,'m h-1', 'm h-1','m h-1',NULL,NULL,13,1,'ohdp')
 ,(41,'kg m-3', 'kg m-3','kg m-3',NULL,NULL,14,1,'ohdp')
 ,(42,'mg l-1', 'mg l-1','mg l-1',NULL,NULL,14,1,'ohdp')
 ,(43,'g m-3', 'g m-3','g m-3',NULL,NULL,14,1,'ohdp')
 ,(44,'mg dm-3', 'mg dm-3','mg dm-3',NULL,NULL,14,1,'ohdp')
 ,(45,'g l-1', 'g l-1','g l-1',NULL,NULL,14,1,'ohdp')
 ,(46,'g s-1', 'g s-1','g s-1',NULL,NULL,15,1,'ohdp')
 ,(47,'kg s-1', 'kg s-1','kg s-1',NULL,NULL,15,1,'ohdp')
 ,(48,'kg h-1', 'kg h-1','kg h-1',NULL,NULL,15,1,'ohdp')
 ,(49,'kg d-1', 'kg d-1','kg d-1',NULL,NULL,15,1,'ohdp')
 ,(50,'pascal', 'Pa','kg s-2 m-1',NULL,NULL,16,1,'ohdp')
 ,(51,'bar', 'bar','Mg ds-2 m-1',NULL,NULL,16,1,'ohdp')
 ,(52,'psi', 'psi','slug ft s-2 inc-2',NULL,NULL,16,1,'ohdp')
 ,(53,'kg m-1 s-1', 'kg m-1 s-1','kg m-1 s-1',NULL,NULL,17,1,'ohdp')
 ,(54,'m2 s-1', 'm2 s-1','m2 s-1',NULL,NULL,18,1,'ohdp')
 ,(55,'watt', 'W','kg m2 s-3',NULL,NULL,19,1,'ohdp')
 ,(56,'kW', 'kW','Mg m3 s-3',NULL,NULL,19,1,'ohdp')
 ,(57,'joule', 'J','kg m2 s-2',NULL,NULL,20,1,'ohdp')
 ,(58,'volt', 'V','kg m2 s-3 A-1',NULL,NULL,21,1,'ohdp')
 ,(59,'hertz', 'Hz','s-1',NULL,NULL,22,1,'ohdp')
 ,(60,'Bq', 'Bq','s-1',NULL,NULL,22,1,'ohdp')
 ,(61,'coulomb', 'C','A s',NULL,NULL,23,1,'ohdp')
 ,(62,'farad', 'F','kg-1 m-2 s4 A2',NULL,NULL,24,1,'ohdp')
 ,(63,'ohm', 'O','kg m2 s-3 A-2',NULL,NULL,25,1,'ohdp')
 ,(64,'siemens', 'S','kg-1 m-2 s3 A2',NULL,NULL,26,1,'ohdp')
 ,(65,'Wb', 'Wb','kg m2 s-2 A-1',NULL,NULL,27,1,'ohdp')
 ,(66,'tesla', 'T','kg s-2 A-1',NULL,NULL,28,1,'ohdp')
 ,(67,'kg m2 s-2 A-2', 'kg m2 s-2 A-2','kg m2 s-2 A-2',NULL,NULL,29,1,'ohdp')
 ,(68,'m-2 cd', 'm-2 cd','m-2 cd',NULL,NULL,30,1,'ohdp')
 ,(69,'m2 s-2', 'm2 s-2','m2 s-2',NULL,NULL,31,1,'ohdp')
 ,(70,'mol s-1', 'mol s-1','mol s-1',NULL,NULL,32,1,'ohdp')
 ,(71,'g mol-1 ', 'g mol-1 ','g mol-1',NULL,NULL,33,1,'ohdp')
 ,(72,'mm', 'mm','mm',NULL,NULL,0,1,'ohdp')
 ,(73,'cm', 'cm','cm',NULL,NULL,0,1,'ohdp')
 ,(74,'l d-1', 'l d-1','l d-1',NULL,NULL,9,1,'ohdp')
 ,(75,'mbar', 'mbar','kg ds-2 m-1',NULL,NULL,16,1,'ohdp')
 ,(76,'dag', 'dag','dag',NULL,NULL,1,1,'ohdp')
 ,(77,'l h-1', 'l h-1','l h-1',NULL,NULL,9,1,'ohdp')
 ,(79,'-', '-','-',NULL,NULL,100,1,'ohdp')
 ,(80,'hours power', 'hp','hp',NULL,NULL,19,0,'ohdp')
 ,(81,'μm', 'μm','μm',NULL,NULL,0,1,'ohdp')
 ,(84,'dm3 d-1m', 'dm3 d-1','dm3 d-1',NULL,NULL,9,1,'bmolnar')
 ,(87,'kg s-3', 'kg s-3','kg s-3',NULL,NULL,34,1,'bmolnar')
 ,(88,'kg s-2', 'kg s-2','kg s-2',NULL,NULL,35,1,'bmolnar')
 ,(89,'kg s-1', 'kg s-1 m-2','kg s-1 m-2',NULL,NULL,36,1,'bmolnar')
 ,(90,'kg h-1', 'kg h-1 m-2','kg h-1 m-2',NULL,NULL,36,1,'bmolnar')
 ,(91,'g m-2', 'gms','gsm',NULL,NULL,37,1,'bmolnar')
 ,(92,'kg m-2', 'kg m-2','kg m-2',NULL,NULL,37,1,'bmolnar')
) AS Source ([Id],[Name],[Abbreviation],[Representation],[FirstOrder],[ZerothOrder],[TypeId],[IsValid],[User])
ON (Target.[Id] = Source.[Id])
WHEN MATCHED AND (Target.[Abbreviation] <> Source.[Abbreviation] OR Target.[Name] <> Source.[Name] OR Target.[Representation] <> Source.[Representation] OR Target.[FirstOrder] <> Source.[FirstOrder] OR Target.[ZerothOrder] <> Source.[ZerothOrder] OR Target.[TypeId] <> Source.[TypeId] OR Target.[IsValid] <> Source.[IsValid] OR Target.[User] <> Source.[User]) THEN
 UPDATE SET
 [Name] = Source.[Name],
 [Abbreviation] = Source.[Abbreviation], 
[Representation] = Source.[Representation], 
[FirstOrder] = Source.[FirstOrder], 
[ZerothOrder] = Source.[ZerothOrder], 
[TypeId] = Source.[TypeId], 
[IsValid] = Source.[IsValid],
[User] = Source.[User]
WHEN NOT MATCHED BY TARGET THEN
 INSERT([Id],[Name], [Abbreviation],[Representation],[FirstOrder],[ZerothOrder],[TypeId],[IsValid],[User])
 VALUES(Source.[Id],Source.[Name],Source.[Abbreviation],Source.[Representation],Source.[FirstOrder],Source.[ZerothOrder],Source.[TypeId],Source.[IsValid], Source.[User])
WHEN NOT MATCHED BY SOURCE THEN 
 DELETE;
 
GO
DECLARE @mergeError int
 , @mergeCount int
SELECT @mergeError = @@ERROR, @mergeCount = @@ROWCOUNT
IF @mergeError != 0
 BEGIN
 PRINT 'ERROR OCCURRED IN MERGE FOR [common].[MeasurementUnit]. Rows affected: ' + CAST(@mergeCount AS VARCHAR(100)); -- SQL should always return zero rows affected
 END
ELSE
 BEGIN
 PRINT '[common].[MeasurementUnit] rows affected by MERGE: ' + CAST(@mergeCount AS VARCHAR(100));
 END
GO
 
SET IDENTITY_INSERT [common].[MeasurementUnit] OFF
GO
SET NOCOUNT OFF
GO
 
 
