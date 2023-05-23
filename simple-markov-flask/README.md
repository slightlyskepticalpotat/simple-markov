# chenanthony-markov
Flask frontend for the [simple-markov](https://github.com/slightlyskepticalpotat/simple-markov) script.

The app sets the configuration variables `HCAPTCHA_SITEKEY` and `HCAPTCHA_SECRET` from a `settings.py` located in the same folder as `app.py`. It has to look something like:

```python
HCAPTCHA_SITEKEY = "Some Sitekey"
HCAPTCHA_SECRET = "Some Secret"
```
