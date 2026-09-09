# Microfiche search — 8 September 2026

**No additional original RUNUP or CHAMP source listing was located in this pass.** The search did establish accessible, recently scanned FEMA microfiche with physical box/envelope identifiers, including records whose catalog titles are still only archive IDs. Their OCR must be searched independently of catalog metadata. This is a useful recovery route, but the inspected matches are community studies, not the missing development sources.

## Material actually inspected

The Internet Archive metadata query for FEMA as creator/publisher in `collection:microfiche` returned 634 records. The wave-title query identified 22 FEMA wave-height studies; their catalog metadata and public OCR were downloaded and screened. Ten additional, poorly titled records were inspected after full-text searches exposed them. The resulting [32-record index](inspected-records.json) preserves identifiers, verbatim catalog numbers, physical box/envelope fields, OCR hashes, and retrieval URLs. The corresponding raw metadata is in [catalogs](catalogs/).

This was catalog/OCR screening, not visual inspection of every frame. No `FORTRAN` or `SUBROUTINE` occurrences were found in these 32 OCR texts. That does not prove a code listing is absent from every image: OCR can fail, and source programs can lack those particular words.

One representative fiche-derived [PDF](micro_IA41152602_0215.pdf) is retained: *Flood insurance study: wave height analysis: Village of Sea Ranch Lakes, Florida, Broward County*, June 15, 1982. [Archive record](https://archive.org/details/micro_IA41152602_0215): box **IA41152602**, envelope **0215**, one card, 15 images, scanned May 29, 2026; metadata reports 400 ppi. The catalog number is transcribed there as `FEMI 1.209: 120056`; the cover identifies community 120056. A cover-image extraction was visually inspected, confirming the document identity. Other page-image extraction encountered a missing JBIG2 decoder; no complete visual review is claimed. This PDF is search evidence, not program source.

Particularly relevant untitled records resolved through metadata/OCR:

| Archive identifier | Catalog number as recorded | Identification / result |
| --- | --- | --- |
| micro_IA41152808_0691 | FEM 1.209: 445399 | Jamestown, Rhode Island, 1986; cites the November 1981 manual |
| micro_IA41152808_0692 | FEM 1.209: 445406 | Providence, Rhode Island, 1986; cites the manual |
| micro_IA41152808_0693 | FEM 1.209: 445410 | Westerly, Rhode Island, 1986; cites the manual |
| micro_IA41152808_0675 | FEM 1.209: 330232 | Community study; methodology/citation material |
| micro_IA41152823_0161 | FEM 1.209: 330135 | New Castle, New Hampshire; references the 1981 manual |

## Search coverage and limits

Queries were run through the Archive's **Text Contents** search, rather than treating advanced metadata search as a search of document contents. Results and counts are observations on the search date, not permanent catalog facts.

| Full-text query | Observed result | Interpretation |
| --- | --- | --- |
| `"Manual for Wave Runup Analysis"` | 15 results | Fiche matches were community studies citing the manual; two book results also appeared. No standalone original manual identified. |
| `"FEMA Wave Runup Model"` | 2 results | Coastal-engineering conference proceedings and a handbook; no fiche source identified. |
| `RUNUP AND FORTRAN` | 31 results | Included Government Reports Announcements indexes and other coastal models; not evidence that each match concerns FEMA RUNUP. |
| `RUNUP2` | 0 | OCR/search negative only. |
| `SIMPCOMP1` | 0 | OCR/search negative only. |
| `(SIMPCOMP OR RRUFF OR RFILES) AND collection:microfiche` | 40 | Mostly unrelated OCR matches; no plausible FEMA source title on the returned list. |
| `(SIMPCOMP OR RRUFF OR RFILES) AND RUNUP` | 0 | OCR/search negative only. |

Public OCR of *Government Reports Announcements & Index* issues 1982-08-13 (82/17), 1989-03-01 (89/5), and 1996-09-01 (96/17) was also searched. Runup entries examined led to other reports, including Ahrens' structure/runup work and Queensland field measurements, rather than the requested FEMA source. These indexes are microfilm-derived serial material, not evidence of a FEMA program fiche holding.

National Archives catalog exact-phrase `"wave runup"` returned eight records; none identified the original software/manual. [Record Group 311's guide](https://www.archives.gov/research/guide-fed-records/groups/311.html) describes FEMA records and notes copies of FEMA publications in Record Group 287. This is a custodial lead, not a confirmed accession for RUNUP source. No specific source-bearing NARA box or fiche number was established.

## Current FEMA library route

The live FRiSEL search was accessible. A RUNUP keyword search returned 318 results, with the initial page dominated by later project data; `microfiche` returned two Utah Lake project records. These are metadata searches and cannot rule out source files inside unexamined study submissions. The preserved [FRiSEL user guide](FRISEL_User_Guide.pdf) explains search behavior; the [2017 data guide](EL_Data_Guide.pdf) documents limits in what is available through the library interface. Their historical contact details should not be assumed current.

The current [Archived Flood Data service](https://hazards.fema.gov/flood-maps/archived-flood-data/home), inspected in a browser on September 8, 2026, explicitly lists **FEMA Software and User Manuals — Applications and user manuals** among its data offerings. It allows signed-in users to request material and communicate with Engineering Library staff. It also publishes research fees and a delay notice. No account, paid order, or request was submitted. This service has not confirmed possession of the missing source.

Its current [contact page](https://hazards.fema.gov/flood-maps/archived-flood-data/contact) routes assistance through **FEMA-FMIX@fema.dhs.gov** and **877-336-2627**. The [prepared inquiry](SOURCE_REQUEST_DRAFT.md) asks staff to locate source-bearing holdings and associated media, rather than simply send the modern RUNUP reconstruction or the already recovered manuals. Sending it requires user authorization to contact others.

All preserved research downloads and raw metadata have sizes, URLs, and SHA-256 hashes in [evidence-manifest.json](evidence-manifest.json). This evidence is kept separate from the original-source manifest.
